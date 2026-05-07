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

enum file_status file_get_events(struct event events[EVENT_MAX])
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

        events[index_event] = event;
        index_event++;
    }

    for (int i = 0; i < 2; i++)
    {
        printf("%d. event:\n", i);
        printf("\t%d\n", events[i].id);
        printf("\t%s\n", events[i].title);
        printf("\t%s\n", events[i].description);
        printf("\t%d\n", events[i].timestamp.tm_year);
        printf("\t%d\n", events[i].timestamp.tm_mon);
        printf("\t%d\n", events[i].timestamp.tm_mday);
        printf("\t%d\n", events[i].type);
        printf("\n");
    }

    file_close(&file);

    return FILE_STATUS_OK;
}
