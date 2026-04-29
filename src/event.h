#ifndef EVENT_H
#define EVENT_H

#include <time.h>

struct event {
    char title[50];
    char description[200];
    struct tm timestamp;
    int type;
};

struct event event_init(void);

#endif
