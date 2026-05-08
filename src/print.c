#include <stdarg.h>

#include "print.h"

#define DEFAULT_PAGER "less -R"

static FILE *pager = NULL;

enum pager_status print_init(void)
{
    if (pager)
        return PAGER_STATUS_ALREADY_INITIALIZED;

    pager = popen(DEFAULT_PAGER, "w");
    if (!pager)
        return PAGER_STATUS_FAILED;

    return PAGER_STATUS_OK;
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

void print_close(void)
{
    if (pager)
    {
        pclose(pager);
        pager = NULL;
    }
}
