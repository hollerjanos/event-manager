#ifndef EVENT_H
#define EVENT_H

#include <sys/types.h>
#include <time.h>
#include <stdio.h>

enum event_part {
        EVENT_PART_ID               = 0,
        EVENT_PART_TITLE            = 1,
        EVENT_PART_DESCRIPTION      = 2,
        EVENT_PART_TIMESTAMP_YEAR   = 3,
        EVENT_PART_TIMESTAMP_MONTH  = 4,
        EVENT_PART_TIMESTAMP_DAY    = 5,
        EVENT_PART_TIMESTAMP_HOUR   = 6,
        EVENT_PART_TIMESTAMP_MINUTE = 7,
        EVENT_PART_TIMESTAMP_SECOND = 8,
        EVENT_PART_TYPE             = 9
};

enum event_type {
        EVENT_TYPE_BIRTHDAY    = 1,
        EVENT_TYPE_NAME_DAY    = 2,
        EVENT_TYPE_ANNIVERSARY = 3
};

struct event {
        id_t id;
        char title[50];
        char description[200];
        struct tm timestamp;
        enum event_type type;
};

struct event event_decode(char *line);

void event_print(struct event e);

#endif
