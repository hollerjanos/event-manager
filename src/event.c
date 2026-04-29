#include "event.h"
#include <string.h>

struct event event_init(void)
{
    struct event event;

    strcpy(event.title, "Test title");
    strcpy(event.description, "Test description");
    event.type = 1;

    return event;
}
