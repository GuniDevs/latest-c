#ifndef TASKS_H
#define TASKS_H

#include <stddef.h>

#define TASK_MAX 32
#define TASK_TITLE_MAX 64

typedef struct {
    char title[TASK_TITLE_MAX];
    int done;
} Task;

typedef struct {
    Task items[TASK_MAX];
    size_t count;
} TaskList;

void tasks_init(TaskList *list);
/* Returns the new task's index, or -1 if the list is full or the title is empty. */
int tasks_add(TaskList *list, const char *title);
/* Returns 0 on success, -1 if the index does not exist. */
int tasks_complete(TaskList *list, size_t index);
size_t tasks_open_count(const TaskList *list);

#endif
