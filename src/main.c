#include <stdio.h>

// #include "event.h"

#include "file.h"

int main(void)
{
    FILE *file = file_open();
    if (file)
    {
        printf("File opened successfully!\n");
        file_close(file);
    }

    // struct event event;
    //
    // event = event_init();
    //
    // printf("Title: %s\n", event.title);
    // printf("Description: %s\n", event.description);
    // printf("Type: %d\n", event.type);

    return 0;
}
