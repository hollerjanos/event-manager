#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "event.h"
#include "color.h"
#include "print.h"

#define EVENT_DELIMITER ":"

static void event_set_event_data_by_part(struct event *e, size_t i, char *d)
{
        switch (i)
        {
                case EVENT_PART_ID:
                        e->id = atoi(d);
                        break;
                case EVENT_PART_TITLE:
                        strcpy(e->title, d);
                        break;
                case EVENT_PART_DESCRIPTION:
                        strcpy(e->description, d);
                        break;
                case EVENT_PART_TIMESTAMP_YEAR:
                        e->timestamp.tm_year = atoi(d);
                        break;
                case EVENT_PART_TIMESTAMP_MONTH:
                        e->timestamp.tm_mon = atoi(d);
                        break;
                case EVENT_PART_TIMESTAMP_DAY:
                        e->timestamp.tm_mday = atoi(d);
                        break;
                case EVENT_PART_TIMESTAMP_HOUR:
                        e->timestamp.tm_hour = atoi(d);
                        break;
                case EVENT_PART_TIMESTAMP_MINUTE:
                        e->timestamp.tm_min = atoi(d);
                        break;
                case EVENT_PART_TIMESTAMP_SECOND:
                        e->timestamp.tm_sec = atoi(d);
                        break;
                case EVENT_PART_TYPE:
                        e->type = atoi(d);
                        break;
        }
}

struct event event_decode(char *line)
{
        struct event e;

        char *t = strtok(line, EVENT_DELIMITER);
        size_t i = 0;

        while (t != NULL)
        {
                event_set_event_data_by_part(&e, i, t);
                t = strtok(NULL, EVENT_DELIMITER);
                i++;
        }

        return e;
}

static inline char *event_get_type_as_string(enum event_type t)
{
        switch (t)
        {
                case EVENT_TYPE_BIRTHDAY: return "Birthday";
                case EVENT_TYPE_NAME_DAY: return "Name day";
                case EVENT_TYPE_ANNIVERSARY: return "Anniversary";
                default: return "Unknown";
        }
}

void event_print(struct event e)
{
        print(COLOR_BLUE "ID:\t\t" COLOR_GREEN "%d\n",
              e.id);
        print(COLOR_BLUE "Title:\t\t" COLOR_MAGENTA "%s\n",
              e.title);
        print(COLOR_BLUE "Description:\t" COLOR_CYAN "%s\n",
              e.description);
        print(COLOR_BLUE "Timestamp:\t" COLOR_YELLOW "%d-%02d-%02d %02d:%02d:%02d\n",
              e.timestamp.tm_year,
              e.timestamp.tm_mon,
              e.timestamp.tm_mday,
              e.timestamp.tm_hour,
              e.timestamp.tm_min,
              e.timestamp.tm_sec);
        print(COLOR_BLUE "Type:\t\t" COLOR_RED "%s\n",
              event_get_type_as_string(e.type));
}
