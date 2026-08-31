#ifndef PRINT_H
#define PRINT_H

enum print_status {
	PRINT_STATUS_OK = 0,
	PRINT_STATUS_FAILED,
	PRINT_STATUS_ALREADY_INITIALIZED
};

enum print_status print_init(void);

void print(const char *format, ...);

void print_free(void);

#endif
