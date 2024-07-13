connection avec level0 / level0

il faut regarder a l'interrieur de l'executable level0

gdb level0
layout asm

0x8048f12 <main+82>     mov    0x1c(%esp),%eax             
   │0x8048f16 <main+86>     mov    %eax,0x4(%esp)       
   │0x8048f1a <main+90>     mov    0x1c(%esp),%eax      
   │0x8048f1e <main+94>     mov    %eax,(%esp)          
   │0x8048f21 <main+97>     call   0x8054700 <setresgid>
   │0x8048f26 <main+102>    mov    0x18(%esp),%eax      
   │0x8048f2a <main+106>    mov    %eax,0x8(%esp)       
   │0x8048f2e <main+110>    mov    0x18(%esp),%eax      
   │0x8048f32 <main+114>    mov    %eax,0x4(%esp)       
   │0x8048f36 <main+118>    mov    0x18(%esp),%eax      
   │0x8048f3a <main+122>    mov    %eax,(%esp)          
   │0x8048f3d <main+125>    call   0x8054690 <setresuid>
   │0x8048f42 <main+130>    lea    0x10(%esp),%eax      
   │0x8048f46 <main+134>    mov    %eax,0x4(%esp)       
   │0x8048f4a <main+138>    movl   $0x80c5348,(%esp)    
   │0x8048f51 <main+145>    call   0x8054640 <execv>    
   │0x8048f56 <main+150>    jmp    0x8048f80 <main+192> 
   │0x8048f58 <main+152>    mov    0x80ee170,%eax       
   │0x8048f5d <main+157>    mov    %eax,%edx            
   │0x8048f5f <main+159>    mov    $0x80c5350,%eax      
   │0x8048f64 <main+164>    mov    %edx,0xc(%esp)       
   │0x8048f68 <main+168>    movl   $0x5,0x8(%esp)       
   │0x8048f70 <main+176>    movl   $0x1,0x4(%esp)       
   │0x8048f78 <main+184>    mov    %eax,(%esp)          
   │0x8048f7b <main+187>    call   0x804a230 <fwrite>   
   │0x8048f80 <main+192>    mov    $0x0,%eax            
   │0x8048f85 <main+197>    leave                       
   │0x8048f86 <main+198>    ret


   ou decompiler le binaire

   scp level0 [user]@[ip]:[path]

   en lancant le binaire dans hex ray ou ghidra on obtient :

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


on peux donc voir que si on ecrit 423 en argument on obtient un shell avec les droits de l'utilisateur level1
on a donc juste a lancer le binaire avec l'argument 423 et écrire cat /home/user/level1/.pass pour obtenir le flag