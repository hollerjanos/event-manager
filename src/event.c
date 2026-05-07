#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "event.h"

struct event event_decode(char *line)
{
    struct event event;
    char *token = strtok(line, ":");
    unsigned int index_token = 0;

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

    return event;
}

void event_print(struct event event)
{
    printf("ID: %d\n", event.id);
    printf("Title: %s\n", event.title);
    printf("Description: %s\n", event.description);
    printf("Timestamp: %d-%d-%d\n",
        event.timestamp.tm_year,
        event.timestamp.tm_mon,
        event.timestamp.tm_mday
    );
    printf("Type: %d\n", event.type);
}
