#ifndef FILE_H
#define FILE_H

#include <stdio.h>

#define FILENAME ".events.txt"

#define MAX_PATH_SIZE 512
#define MAX_LINE_SIZE 255

enum file_status {
	FILE_STATUS_OK,
	FILE_STATUS_FAILED,
	FILE_STATUS_ALREADY_INITIALIZED,
	FILE_STATUS_HOME_UNKNOWN
};

enum file_status
file_init(void);

void
file_free(void);

enum file_status
file_get_events(void);

#endif
