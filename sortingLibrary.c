//
// Created by ilya on 08.10.2020.
//

#include "sortingLibrary.h"

int linecmp(const char *s1, const char *s2, int type) {
    const char *line[2] = {s1, s2};
    int len[2] = {strlen(s1), strlen(s2)},
            pos[2] = {0, 0},
            end[2] = {0, 0},
            step = type;

    if (type == FORWARD) {
        end[0] = len[0] - 1;
        end[1] = len[1] - 1;
    }
    else if (type == BACKWARD){
        pos[0] = len[0] - 1;
        pos[1] = len[1] - 1;
    }

    while (pos[0] * step <= end[0] && pos[1] * step <= end[1]) {
        for (int i = 0; i <= 1; ++i) {
            while (pos[i] * step <= end[i] && !(line[i][pos[i]] >= 'A' && line[i][pos[i]] <= 'Z'
                                                || line[i][pos[i]] >= 'a' && line[i][pos[i]] <= 'z')) {
                pos[i] += step;
            }
        }

        if (pos[0] * step <= end[0] && pos[1] * step <= end[1]) {
            char symbolFirst = tolower(s1[pos[0]]),
                    symbolSecond = tolower(s2[pos[1]]);
            if (symbolFirst < symbolSecond)
                return -1;
            if (symbolFirst > symbolSecond)
                return 1;
        }
        pos[0] += step;
        pos[1] += step;
    }

    if (pos[0] == pos[1])
        return 0;
    if (pos[0] * step > pos[1] * step)
        return -1;
    if (pos[0] * step < pos[1] * step)
        return 1;

    return 0;
}

void qSort(char **line, int left, int right, int type) {
    if (left < right) {
        char* last = line[right];
        int lt = left, rt = right;

        while (rt > lt) {
            //while (strcmp(line[lt], last) < 0)
            while (linecmp(line[lt], last, type) < 0)
                ++lt;

            while (linecmp(line[rt], last, type) > 0)
                --rt;

            if (lt <= rt) {
                char* temp = line[rt];
                line[rt] = line[lt];
                line[lt] = temp;
                ++lt;
                --rt;
            }
        }

        qSort(line, left, rt, type);
        qSort(line, lt, right, type);
    }
}

void quickSort(char **line, int cntLines, int type) {
    qSort(line, 0, cntLines - 1, type);
}