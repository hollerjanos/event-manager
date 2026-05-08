#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "event-manager.h"
#include "print.h"

void event_manager_init(struct event_manager *em)
{
    em->capacity = 10;
    em->count = 0;
    em->events = malloc(sizeof(struct event) * em->capacity);
}

static inline bool event_manager_is_full(struct event_manager *em)
{
    return em->count == em->capacity;
}

static void event_manager_increase_capacity(struct event_manager *em)
{
    em->capacity *= 2;
    em->events = realloc(em->events, sizeof(struct event) * em->capacity);
}

void event_manager_add(struct event_manager *em, struct event e)
{
    if (event_manager_is_full(em)) event_manager_increase_capacity(em);

    em->events[em->count++] = e;
}

void event_manager_free(struct event_manager *em)
{
    free(em->events);

    em->count = 0;
    em->events = NULL;
}

void event_manager_print(struct event_manager *em)
{
    if (print_init() == PAGER_STATUS_FAILED)
    {
        fprintf(stderr, "Couldn't initialize pager!\n");
        return;
    }

    for (size_t index = 0; index < em->count; index++)
    {
        if (index != 0) print("\n");
        event_print(em->events[index]);
    }

    print_close();
}
