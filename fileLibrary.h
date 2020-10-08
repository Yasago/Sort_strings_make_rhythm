//
// Created by ilya on 08.10.2020.
//

#ifndef SORT_STRINGS_FILELIBRARY_H
#define SORT_STRINGS_FILELIBRARY_H

#include <stddef.h>
#include <bits/types/FILE.h>

#define ERROR_OPEN_FILE -3

char **strings;
char *buffer;

///
/// \param path Path to file to read from
/// \param fout Stream to file to write to
/// \return amount of read strings
int readAndWriteDefaultFile(const char* path, FILE* fout);

///
/// \param fout Stream to file to write to
/// \param cntStrings amount of read strings
/// \return Stream to file to write to
FILE* writeSortedText(FILE* fout, int cntStrings);

///
/// \param fout Stream to file to write to
/// \param cntStrings amount of read strings
void writeReverseSortedFile(FILE* fout, int cntStrings);

#endif //SORT_STRINGS_FILELIBRARY_H
