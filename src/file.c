#include <stdlib.h>
#include <string.h>

#include "file.h"

static FILE *file_open(void)
{
    const char *home = getenv("HOME");
    if (!home) return NULL;

    char path[MAX_PATH_SIZE];
    snprintf(path, sizeof(path), "%s/%s", home, FILENAME);

    return fopen(path, "r");
}

static void file_close(FILE **file)
{
    if (file && *file)
    {
        fclose(*file);
        *file = NULL;
    }
}

static void file_process_lines(FILE *file, struct event_manager *em)
{
    char line[MAX_LINE_SIZE];

    struct event event;

    while (fgets(line, MAX_LINE_SIZE, file))
    {
        event = event_decode(line);
        
        event_manager_add(em, event);
    }
}

enum file_status file_get_events(struct event_manager *em)
{
    FILE *file = file_open();
    if (!file) return FILE_STATUS_COULD_NOT_OPEN;

    file_process_lines(file, em);

    file_close(&file);

    return FILE_STATUS_OK;
}
