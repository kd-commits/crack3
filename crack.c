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

int alphabetic(const void *a, const void *b);
int strsearch(const void *key, const void *elem);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }
    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    // Read the hashes file into an array.
    int size;
    char **hashes = loadFileAA(argv[1], &size);

    // CHALLENGE1: Sort the hashes using qsort.
    qsort(hashes, size, sizeof(char*), alphabetic);

    // TODO
    // Open the password file for reading.
    FILE *d = fopen(argv[2], "r");
    if (!d)
    {
        puts("Cant open dictionary for reading");
        exit(1);
    }


    // TODO:
>>>>>>> b576cd3 (qsort challenge | +comments)
    // For each password, hash it, then use the array search
    // function from fileutil.h to find the hash.
    // If you find it, display the password and the hash.
    // Keep track of how many hashes were found.
    // CHALLENGE1: Use binary search instead of linear search.

<<<<<<< HEAD
=======
<<<<<<< HEAD
    // TODO
=======
>>>>>>> b576cd3 (qsort challenge | +comments)
    char *line = malloc(PASS_LEN * sizeof(char));
    int count = 0;
    while (fgets(line, PASS_LEN, d))
    {
		char *nl = strchr(line, '\n');
		if (nl) *nl = '\0';
		
        char *target = md5(line, strlen(line));
        char *found = substringSearchAA(target, hashes, size); // linear search
        if (found)
        {
            printf("%s %s\n", line, found);
            count++;
        }
    }

<<<<<<< HEAD
=======
>>>>>>> 6f84749 (qsort challenge | +comments)
>>>>>>> b576cd3 (qsort challenge | +comments)
    // When done with the file:
    //   Close the file
    //   Display the number of hashes found.
    //   Free up memory.
<<<<<<< HEAD

    fclose(d);
    printf("%d hashes cracked!\n", count);
    free(line);
    freeAA(hashes, size);
}
=======
<<<<<<< HEAD
}
=======

    fclose(d);
    printf("%d hashes cracked!\n", count);
    free(line);
    freeAA(hashes, size);
}
>>>>>>> b576cd3 (qsort challenge | +comments)

int alphabetic(const void *a, const void *b)
{
    char ** aa = (char **)a;
    char ** bb = (char **)b;

    return strcmp(*aa,*bb);
}

int strsearch(const void *key, const void *elem)
{
    return strcmp((char**)key, (char**)elem);
<<<<<<< HEAD
}
=======
}
>>>>>>> 6f84749 (qsort challenge | +comments)
>>>>>>> b576cd3 (qsort challenge | +comments)
