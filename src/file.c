#include <stdlib.h>
#include <string.h>

#include "file.h"

static FILE *file = NULL;

enum file_status file_init(void)
{
	if (file)
		return FILE_STATUS_ALREADY_INITIALIZED;

	const char *home = getenv("HOME");
	if (!home)
		return FILE_STATUS_HOME_UNKNOWN;

	char path[MAX_PATH_SIZE];
	snprintf(path, sizeof(path), "%s/%s", home, FILENAME);

	file = fopen(path, "a+");
	if (!file)
		return FILE_STATUS_FAILED;

	return FILE_STATUS_OK;
}

void file_free(void)
{
	if (file)
	{
		fclose(file);
		file = NULL;
	}
}

static void file_process_lines(void)
{
	char line[MAX_LINE_SIZE];

	struct event event;

	while (fgets(line, MAX_LINE_SIZE, file))
	{
		event = event_decode(line);

		event_manager_add(event);
	}
}

enum file_status file_get_events(void)
{
	if (!file)
		return FILE_STATUS_FAILED;

	file_process_lines();

	return FILE_STATUS_OK;
}
