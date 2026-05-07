#include <stdio.h>

#include "event-manager.h"

#include "file.h"

int main(void)
{
    struct event_manager em;

    event_manager_init(&em);

    file_get_events(&em);

    event_manager_free(&em);

    // struct event *events;

    // file_get_events(events);

    // struct event event;
    //
    // event = event_init();
    //
    // printf("Title: %s\n", event.title);
    // printf("Description: %s\n", event.description);
    // printf("Type: %d\n", event.type);

    return 0;
}
