#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#include "event-manager.h"

#define FILENAME ".events.txt"

#define MAX_PATH_SIZE 512
#define MAX_LINE_SIZE 255

enum file_status {
    FILE_STATUS_OK = 0,
    FILE_STATUS_COULD_NOT_OPEN
};

enum file_status file_get_events(struct event_manager *em);

#endif
