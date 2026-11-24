#include "tasks.h"

#include <string.h>

void tasks_init(TaskList *list) {
    memset(list, 0, sizeof(*list));
}

int tasks_add(TaskList *list, const char *title) {
    if (title == NULL || title[0] == '\0' || list->count >= TASK_MAX) {
        return -1;
    }
    Task *t = &list->items[list->count];
    strncpy(t->title, title, TASK_TITLE_MAX - 1);
    t->title[TASK_TITLE_MAX - 1] = '\0';
    t->done = 0;
    return (int)list->count++;
}

int tasks_complete(TaskList *list, size_t index) {
    if (index >= list->count) {
        return -1;
    }
    list->items[index].done = 1;
    return 0;
}

size_t tasks_open_count(const TaskList *list) {
    size_t open = 0;
    for (size_t i = 0; i < list->count; i++) {
        if (!list->items[i].done) {
            open++;
        }
    }
    return open;
}
