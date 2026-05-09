#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <sys/types.h>

#include "event.h"

enum event_manager_status {
        EVENT_MANAGER_STATUS_OK = 0,
        EVENT_MANAGER_STATUS_FAILED,
        EVENT_MANAGER_STATUS_ALREADY_INITIALIZED
};

struct event_manager {
        struct event *events;
        size_t count;
        size_t capacity;
};

enum event_manager_status event_manager_init(void);

void event_manager_add(struct event e);

void event_manager_free(void);

enum event_manager_status event_manager_print(void);

#endif
