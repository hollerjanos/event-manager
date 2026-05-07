#include <stdlib.h>
#include <stdio.h>

#include "event-manager.h"

void event_manager_init(struct event_manager *em)
{
    em->capacity = 10;
    em->count = 0;
    em->events = malloc(sizeof(struct event) * em->capacity);
}

void event_manager_add(struct event_manager *em, struct event e)
{
    if (em->count == em->capacity) event_manager_increase_capacity(em);

    em->events[em->count++] = e;
}

static void event_manager_increase_capacity(struct event_manager *em)
{
    em->capacity *= 2;
    em->events = realloc(em->events, sizeof(struct event) * em->capacity);
}

void event_manager_free(struct event_manager *em)
{
    free(em->events);

    em->count = 0;
    em->events = NULL;
}

void event_manager_print(struct event_manager *em)
{
    for (size_t index = 0; index < em->count; index++)
    {
        printf("%lu. event:\n", index);
        printf("\t%d\n", em->events[index].id);
        printf("\t%s\n", em->events[index].title);
        printf("\t%s\n", em->events[index].description);
        printf("\t%d\n", em->events[index].timestamp.tm_year);
        printf("\t%d\n", em->events[index].timestamp.tm_mon);
        printf("\t%d\n", em->events[index].timestamp.tm_mday);
        printf("\t%d\n", em->events[index].type);
        printf("\n");
    }
}
