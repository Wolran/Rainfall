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