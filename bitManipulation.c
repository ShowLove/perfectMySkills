#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 2;
	int b = (2|0x0001);
	printf("int a = 2; \nint b = (2|0x0001);\n");
	printf("0010 or 0001 = 0011 = 3\n");
	printf("b(%x) a(%x)\n", b, a);

}