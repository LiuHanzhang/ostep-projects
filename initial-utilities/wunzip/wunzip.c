#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	if(argc == 1)
	{
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}

	for(int i = 1; i < argc; i++)
	{
		FILE *fp = fopen(argv[i], "rb");
		if(fp == NULL)
		{
			printf("wunzip: cannot open file\n");
			exit(1);
		}

		int cnt;
		char c;
		while(fread(&cnt, sizeof(int), 1, fp) == 1 && fread(&c, sizeof(char), 1, fp) == 1)
		{
			while(cnt-- > 0)
				putchar(c);
		}
	}
	return 0;
}
