# Rapport CTF - [Level00]

### Observation :
En arrivant sur le level0 on trouve un exécutable nommé level0. \
Quand nous essayons de le lancer avec un argument le programme nous répond `No !` puis se ferme. \
Regardons donc avec gdb ou un décompilateur. 


### Explication de Code :
En lancant le binaire dans hex-ray ou ghidra nous obtenons :
```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
_DWORD v4[2]; // [esp+10h] [ebp-10h] BYREF
int v5; // [esp+18h] [ebp-8h]
int v6; // [esp+1Ch] [ebp-4h]

if ( atoi(argv[1]) == 423 )
{
v4[0] = strdup("/bin/sh");
v4[1] = 0;
v6 = getegid();
v5 = geteuid();
setresgid(v6, v6, v6);
setresuid(v5, v5, v5);
execv("/bin/sh", v4);
}
else
{
fwrite("No !\n", 1, 5, stderr);
}
return 0;
}
```


### Solution :

On peut donc voir que si on écrit `423` en argument on obtient un shell avec les droits de l'utilisateur level1 \
On a donc juste a lancer le binaire avec l'argument 423 et écrire `cat /home/user/level1/.pass` pour obtenir le flag
