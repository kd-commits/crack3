#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    int size;
    char **hashes = loadFileAA(argv[1], &size);
    puts("File loaded");
    
    FILE *d = fopen(argv[2], "r");
    if (!d)
    {
        puts("Cant open dictionary for reading");
        exit(1);
    }
    
    // malloc line
    char *line = malloc(PASS_LEN * sizeof(char));
    int count = 0;

    while (fgets(line, PASS_LEN, d))
    {
		char *nl = strchr(line, '\n');
		if (nl) *nl = '\0';
		
        char *target = md5(line, strlen(line));
		char *found = substringSearchAA(target, hashes, size);

		if (found)
        {
			printf("%s %s\n", found, target);
            count++;
        }
    }

    fclose(d);
    // free line
    free(line);
    freeAA(hashes, size);
    printf("%d hashes cracked!\n", count);
}