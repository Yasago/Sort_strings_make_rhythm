//
// Created by ilya on 08.10.2020.
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "fileLibrary.h"
#include "sortingLibrary.h"
#include "testLibrary.h"

void basicCheck() {
    FILE *fout = fopen("outTest.txt", "w");
    int cntStrings = readAndWriteDefaultFile("test.txt", fout);
    quickSort(strings, cntStrings, FORWARD);
    writeSortedText(fout, cntStrings);
    quickSort(strings, cntStrings, BACKWARD);
    writeReverseSortedFile(fout, cntStrings);

    fclose(fout);
    FILE *fin;
    fin = fopen("outTest.txt", "r");
    if (fin == NULL) {
        printf("Failed to open file");
        exit(ERROR_OPEN_FILE);
    }

    fseek(fin, 0L, SEEK_END);
    long fileSize = ftell(fin);
    printf("File size: %ld\n", fileSize);
    fclose(fin);

    int fd;
    fd = open("outTest.txt", O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file");
        exit(ERROR_OPEN_FILE);
    }

    free(buffer);
    free(strings);

    buffer = (char *) calloc(fileSize + 1, sizeof(char));
    printf("Program read %zd bytes\n", read(fd, buffer, fileSize));

    buffer[fileSize] = '\0';

    strings = (char **) calloc(1, sizeof(char *));
    //strings[0] = &buffer[0];
    cntStrings = 0;
    for (long i = 1; i < fileSize; ++i) {
        if (buffer[i] == '\n') {
            if (i != fileSize - 1 && buffer[i + 1] == '\n') {
                buffer[i] = '\0';
                continue;
            }
            buffer[i] = '\0';
            if (cntStrings > 0)
                strings = (char **) realloc(strings, (1 + cntStrings) * sizeof(char*));
            strings[cntStrings] = &buffer[i + 1];
            ++cntStrings;
        }
    }

    assert(strcmp(strings[5], "Cherez") == 0);
    assert(strcmp(strings[6], "Ehal") == 0);
    assert(strcmp(strings[7], "Greka") == 0);
    assert(strcmp(strings[8], "Reku") == 0);

    assert(strcmp(strings[10], "Greka") == 0);
    assert(strcmp(strings[11], "Ehal") == 0);
    assert(strcmp(strings[12], "Reku") == 0);
    assert(strcmp(strings[13], "Cherez") == 0);

    free(buffer);
    free(strings);
}
