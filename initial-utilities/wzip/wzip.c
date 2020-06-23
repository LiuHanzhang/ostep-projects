#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}

	char *line = NULL;
	size_t len = 0;

	for(int i = 1; i < argc; i++)
	{
		FILE *fp = fopen(argv[i], "r");
		if(fp == NULL)
		{
			printf("wzip: cannot open file\n");
			exit(1);
		}
		
		//let's assume that all files to be zipped are in one line
		getline(&line, &len, fp);
		char prev = *line;
		int cnt = 1;
		for(char *c = line + 1; *c != '\0'; c++)
		{
			if(*c == prev)
			{
				cnt++;
				continue;
			}
			//else
			fwrite(&cnt, sizeof(int), 1, stdout);
			fwrite(&prev, sizeof(char), 1, stdout);
			cnt = 1;
			prev = *c;
		}
		fwrite(&cnt, sizeof(int), 1, stdout);
		fwrite(&prev, sizeof(char), 1, stdout);
	}

	return 0;
}
