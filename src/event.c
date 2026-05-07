#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "event.h"

struct event event_decode(char *line)
{
    struct event event;
    char *token = strtok(line, EVENT_DELIMITER);
    unsigned int index = 0;

    while (token != NULL)
    {
        switch (index)
        {
            case EVENT_PART_ID:
                event.id = atoi(token);
                break;
            case EVENT_PART_TITLE:
                strcpy(event.title, token);
                break;
            case EVENT_PART_DESCRIPTION:
                strcpy(event.description, token);
                break;
            case EVENT_PART_TIMESTAMP_YEAR:
                event.timestamp.tm_year = atoi(token);
                break;
            case EVENT_PART_TIMESTAMP_MONTH:
                event.timestamp.tm_mon = atoi(token);
                break;
            case EVENT_PART_TIMESTAMP_DAY:
                event.timestamp.tm_mday = atoi(token);
                break;
            case EVENT_PART_TIMESTAMP_HOUR:
                event.timestamp.tm_hour = atoi(token);
                break;
            case EVENT_PART_TIMESTAMP_MINUTE:
                event.timestamp.tm_min = atoi(token);
                break;
            case EVENT_PART_TIMESTAMP_SECOND:
                event.timestamp.tm_sec = atoi(token);
                break;
            case EVENT_PART_TYPE:
                event.type = atoi(token);
                break;
        }

        token = strtok(NULL, EVENT_DELIMITER);
        index++;
    }

    return event;
}

static inline char *event_get_type(enum event_type type)
{
    switch (type)
    {
        case EVENT_TYPE_BIRTHDAY: return "Birthday";
        case EVENT_TYPE_NAME_DAY: return "Name day";
        case EVENT_TYPE_ANNIVERSARY: return "Anniversary";
        default: return "Unknown";
    }
}

void event_print(struct event event)
{
    printf("ID: %d\n", event.id);
    printf("Title: %s\n", event.title);
    printf("Description: %s\n", event.description);
    printf("Timestamp: %d-%02d-%02d %02d:%02d:%02d\n",
        event.timestamp.tm_year,
        event.timestamp.tm_mon,
        event.timestamp.tm_mday,
        event.timestamp.tm_hour,
        event.timestamp.tm_min,
        event.timestamp.tm_sec
    );
    printf("Type: %d = %s\n", event.type, event_get_type(event.type));
}
