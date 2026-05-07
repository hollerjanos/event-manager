#include <stdlib.h>
#include <string.h>

#include "file.h"

static FILE *file_open(void)
{
    const char *home = getenv("HOME");
    if (!home) return NULL;

    char path[512];
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

enum file_status file_get_events(struct event_manager *em)
{
    FILE *file = file_open();
    if (!file) return FILE_STATUS_COULD_NOT_OPEN;

    // TODO: Rewrite this into smaller functions!
    char current_line[255];
    char *token;
    unsigned int index_token = 0;

    struct event event;
    unsigned int index_event = 0;

    while (fgets(current_line, 100, file))
    {
        printf("%s", current_line);
        token = strtok(current_line, ":");
        index_token = 0;
        while (token != NULL)
        {
            switch (index_token)
            {
                case 0: event.id = atoi(token); break;
                case 1: strcpy(event.title, token); break;
                case 2: strcpy(event.description, token); break;
                case 3: event.timestamp.tm_year = atoi(token); break;
                case 4: event.timestamp.tm_mon = atoi(token); break;
                case 5: event.timestamp.tm_mday = atoi(token); break;
                case 6: event.type = atoi(token); break;
            }
            token = strtok(NULL, ":");
            index_token++;
        }

        event_manager_add(em, event);
        index_event++;
    }

    event_manager_print(em);

    file_close(&file);

    return FILE_STATUS_OK;
}
