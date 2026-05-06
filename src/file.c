#include <stdlib.h>

#include "file.h"

FILE *file_open(void)
{
    const char *home = getenv("HOME");
    if (!home) return NULL;

    char path[512];
    snprintf(path, sizeof(path), "%s/%s", home, FILENAME);

    return fopen(path, "r");
}

void file_close(FILE *file)
{
    fclose(file);
}
