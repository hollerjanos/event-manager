#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#include "event.h"

#define FILENAME ".events.txt"

#define EVENT_MAX 100

enum file_status {
    FILE_STATUS_OK = 0,
    FILE_STATUS_COULD_NOT_OPEN
};

static FILE *file_open(void);

static void file_close(FILE **file);

enum file_status file_get_events(struct event events[EVENT_MAX]);

#endif
