#include <stdio.h>

#include "event.h"

int main(void)
{
    struct event event;

    event = event_init();

    printf("Title: %s\n", event.title);
    printf("Description: %s\n", event.description);
    printf("Type: %d\n", event.type);
    return 0;
}
