#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "event-manager.h"
#include "print.h"

#define DEFAULT_CAPACITY 10

static struct event_manager em = {0};

enum event_manager_status event_manager_init(void)
{
        if (em.events)
                return EVENT_MANAGER_STATUS_ALREADY_INITIALIZED;

        em.events = malloc(sizeof(struct event) * DEFAULT_CAPACITY);

        if (!em.events)
                return EVENT_MANAGER_STATUS_FAILED;

        em.capacity = DEFAULT_CAPACITY;
        em.count = 0;

        return EVENT_MANAGER_STATUS_OK;
}

static inline bool event_manager_is_full(void)
{
        return em.count == em.capacity;
}

static void event_manager_increase_capacity(void)
{
        em.capacity *= 2;
        em.events = realloc(em.events, sizeof(struct event) * em.capacity);
}

void event_manager_add(struct event e)
{
        if (event_manager_is_full())
                event_manager_increase_capacity();

        em.events[em.count++] = e;
}

void event_manager_free(void)
{
        free(em.events);

        em.count = 0;
        em.events = NULL;
}

enum event_manager_status event_manager_print(void)
{
        if (print_init() != PRINT_STATUS_OK)
                return EVENT_MANAGER_STATUS_FAILED;

        for (size_t index = 0; index < em.count; index++)
        {
                if (index != 0)
                        print("\n");

                event_print(em.events[index]);
        }

        print_free();

        return EVENT_MANAGER_STATUS_OK;
}
