#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <io.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

#define ERROR_OPEN_FILE -3

int main() {
    int fd;
    fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file");
        getch();
        exit(ERROR_OPEN_FILE);
    }

    FILE* fin;
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Failed to open file");
        //getch();
        exit(ERROR_OPEN_FILE);
    }

    fseek(fin, 0L, SEEK_END);
    int fileSize = ftell(fin);
    printf("File size: %d", fileSize);

    char *buffer;
    buffer = calloc(fileSize, sizeof(char));
    printf("Program read %d bytes\n", read(fd, buffer, fileSize));
    printf("%s", buffer);

    puts("\nFile read successfully\n");

    free(buffer);
    return 0;
}
