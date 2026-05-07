#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "event.h"
#include <sys/types.h>

struct event_manager {
    struct event *events;
    size_t count;
    size_t capacity;
};

void event_manager_init(struct event_manager *em);

void event_manager_add(struct event_manager *em, struct event e);

static void event_manager_increase_capacity(struct event_manager *em);

void event_manager_free(struct event_manager *em);

void event_manager_print(struct event_manager *em);

#endif
