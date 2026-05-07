#ifndef EVENT_H
#define EVENT_H

#include <sys/types.h>
#include <time.h>

struct event {
    id_t id;
    char title[50];
    char description[200];
    struct tm timestamp;
    int type;
};

struct event event_decode(char *line);

void event_print(struct event event);

#endif
