#include <stdio.h>

#include "event-manager.h"

#include "file.h"

int main(void)
{
    struct event_manager em;

    event_manager_init(&em);

    if (file_get_events(&em) != FILE_STATUS_OK)
    {
        printf("There was a problem getting the data!\n");
    }

    event_manager_print(&em);

    event_manager_free(&em);

    return 0;
}
