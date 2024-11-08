#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // Read the hashes file into an array.
    int size;
    char **hashes = loadFileAA(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // Open the password file for reading.
    FILE *d = fopen(argv[2], "r");
    if (!d)
    {
        puts("Cant open dictionary for reading");
        exit(1);
    }

    char *line = malloc(PASS_LEN * sizeof(char));
    int count = 0;

    // CHALLENGE1: Use binary search instead of linear search.
    while (fgets(line, PASS_LEN, d))
    {
        // Trim
        char *nl = strchr(line, '\n');
        if (nl) *nl ='\0';

        // Hash
        char *target = md5(line, sizeof(line));

        // Search
        char *found = substringSearchAA(target, hashes, size);

        if (strcmp(target,found) == 0)
        {
            printf("%s %s\n", found, line);
            count++;
        }

        free(target);
    }
    
    // TODO
    fclose(d);
    printf("%d hashes cracked!\n", count);
    freeAA(hashes, size);
}