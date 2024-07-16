void test()
{
	char str[] = {'L','A','N','G', 1};
	str[4]--;
	(void)write(1, (long)getenv(str), 8);
}

\x55\x89\xe5\x83\xec\x18\xc7\x04\x24\x00\x00\x00\x00\xe8\xfc\xff\xff\xff\xc7\x44\x24\x08\x04\x00\x00\x00\x89\x44\x24\x04\xc7\x04\x24\x01\x00\x00\x00\xe8\xfc\xff\xff\xff\xc9\xc3

   0:   55                      push   %ebp
   1:   89 e5                   mov    %esp,%ebp
   3:   83 ec 18                sub    $0x18,%esp
   6:   c7 04 24 00 00 00 00    movl   $0x0,(%esp)
   d:   e8 fc ff ff ff          call   e <test+0xe>
  12:   c7 44 24 08 04 00 00    movl   $0x4,0x8(%esp)
  19:   00
  1a:   89 44 24 04             mov    %eax,0x4(%esp)
  1e:   c7 04 24 01 00 00 00    movl   $0x1,(%esp)
  25:   e8 fc ff ff ff          call   26 <test+0x26>
  2a:   c9                      leave
  2b:   c3                      ret