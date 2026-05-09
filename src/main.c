#include <stdlib.h>
#include <stdio.h>

#include "event-manager.h"
#include "file.h"

int main(void)
{
        int result = EXIT_FAILURE;

        printf("Event-Manager initialization...\n");
        if (event_manager_init() != EVENT_MANAGER_STATUS_OK)
        {
                fprintf(stderr, "Event-Manager initialization failed!\n");
                goto cleanup;
        }

        printf("File initialization...\n");
        if (file_init() != FILE_STATUS_OK)
        {
                fprintf(stderr, "File initialization failed!\n");
                goto cleanup;
        }

        printf("Getting the events...\n");
        if (file_get_events() != FILE_STATUS_OK)
        {
                fprintf(stderr, "Couldn't get the events!\n");
        }

        printf("Printing the events...\n");
        if (event_manager_print() != EVENT_MANAGER_STATUS_OK)
        {
                fprintf(stderr, "Couldn't print the events!\n");
        }

        result = EXIT_SUCCESS;

cleanup:

        printf("Event-Manager freeing!\n");
        event_manager_free();

        printf("File freeing!\n");
        file_free();

        return result;
}
