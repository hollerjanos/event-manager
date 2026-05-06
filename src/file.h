#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#define FILENAME ".events.txt"

FILE *file_open(void);

void file_close(FILE *file);

#endif
