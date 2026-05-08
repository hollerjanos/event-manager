#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>

enum pager_status {
    PAGER_STATUS_OK = 0,
    PAGER_STATUS_ALREADY_INITIALIZED,
    PAGER_STATUS_FAILED
};

enum pager_status print_init(void);

void print(const char *format, ...);

void print_close(void);

#endif
