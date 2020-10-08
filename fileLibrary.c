//
// Created by ilya on 08.10.2020.
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "fileLibrary.h"

int readAndWriteDefaultFile(const char* path, FILE* fout) {
    int fd;
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file");
        exit(ERROR_OPEN_FILE);
    }

    FILE *fin;
    fin = fopen(path, "r");
    if (fin == NULL) {
        printf("Failed to open file");
        exit(ERROR_OPEN_FILE);
    }

    fseek(fin, 0L, SEEK_END);
    long fileSize = ftell(fin);
    printf("File size: %ld\n", fileSize);
    fclose(fin);

    buffer = (char *) calloc(fileSize + 1, sizeof(char));
    printf("Program read %zd bytes\n", read(fd, buffer, fileSize));

    fputs("Default Text:\n\n", fout);
    fputs(buffer, fout);
    fputs("\n\n", fout);

    buffer[fileSize] = '\0';

    strings = (char **) calloc(1, sizeof(char *));
    strings[0] = &buffer[0];
    int cntStrings = 1;
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

    /*for (int i = 0; i < cntStrings; ++i)
        printf("%s\n", strings[i]);
    puts("\nFile read successfully\n");*/

    return cntStrings;
}

FILE* writeSortedText(FILE* fout, int cntStrings) {

    if (fout == NULL) {
        printf("Failed to open file");
        //getch();
        exit(ERROR_OPEN_FILE);
    }

    fputs("Sorted strings:\n\n", fout);
    for (int i = 0; i < cntStrings - 1; ++i) {
        fputs(strings[i], fout);
        fputc('\n', fout);
    }
    fputs(strings[cntStrings - 1], fout);
    fputs("\n\n", fout);

    return fout;
}

void writeReverseSortedFile(FILE* fout, int cntStrings) {
    fputs("Reverse-sorted strings:\n\n", fout);
    for (int i = 0; i < cntStrings - 1; ++i) {
        fputs(strings[i], fout);
        fputc('\n', fout);
    }
    fputs(strings[cntStrings - 1], fout);
}