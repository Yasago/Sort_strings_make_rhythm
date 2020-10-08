#include <stdio.h>
#include <stdlib.h>
#include "sortingLibrary.h"
#include "testLibrary.h"
#include "fileLibrary.h"


int main() {
    basicCheck();

    FILE *fout;
    fout = fopen("output.txt", "w");
    int cntStrings = readAndWriteDefaultFile("input.txt", fout);

    quickSort(strings, cntStrings, FORWARD);
    writeSortedText(fout, cntStrings);
    quickSort(strings, cntStrings, BACKWARD);
    writeReverseSortedFile(fout, cntStrings);

    fclose(fout);
    free(buffer);
    free(strings);

    return 0;
}

