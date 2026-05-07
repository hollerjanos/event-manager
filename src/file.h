#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#include "event-manager.h"

#define FILENAME ".events.txt"

enum file_status {
    FILE_STATUS_OK = 0,
    FILE_STATUS_COULD_NOT_OPEN
};

static FILE *file_open(void);

static void file_close(FILE **file);

enum file_status file_get_events(struct event_manager *em);

#endif
