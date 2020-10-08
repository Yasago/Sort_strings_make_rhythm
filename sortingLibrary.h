//
// Created by ilya on 08.10.2020.
//

#ifndef SORT_STRINGS_SORTINGLIBRARY_H
#define SORT_STRINGS_SORTINGLIBRARY_H

#include <string.h>
#include <ctype.h>

#define FORWARD 1
#define BACKWARD -1

///
/// \param s1 first string for compare
/// \param s2 second string for compare
/// \param type type of comparing (forwarded type == 1 or backwarded type == -1)
/// \return result of compare
int linecmp(const char *s1, const char *s2, int type);

///
/// \param line array of strings for sorting
/// \param left left bound
/// \param right right bound
/// \param type type of comparing (forwarded type == 1 or backwarded type == -1)
void qSort(char **line, int left, int right, int type);

///
/// \param line array of strings for sorting
/// \param cntLines amount of read strings
/// \param type type of comparing (forwarded type == 1 or backwarded type == -1)
void quickSort(char **line, int cntLines, int type);

#endif //SORT_STRINGS_SORTINGLIBRARY_H
