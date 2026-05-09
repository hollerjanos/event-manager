#include <stdio.h>
#include <stdarg.h>

#include "print.h"

#define PAGER_DEFAULT "less -R"

static FILE *pager = NULL;

enum print_status print_init(void)
{
        if (pager)
                return PRINT_STATUS_ALREADY_INITIALIZED;

        pager = popen(PAGER_DEFAULT, "w");

        if (!pager)
                return PRINT_STATUS_FAILED;

        return PRINT_STATUS_OK;
}

void print(const char *format, ...)
{
        if (!pager)
                return;

        va_list args;

        va_start(args, format);
        vfprintf(pager, format, args);
        va_end(args);
}

void print_free(void)
{
        if (!pager)
                return;

        pclose(pager);
        pager = NULL;
}
