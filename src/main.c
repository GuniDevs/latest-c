#include <stdio.h>

#include "tasks.h"

int main(void) {
    TaskList list;
    tasks_init(&list);
    tasks_add(&list, "write the code");
    tasks_add(&list, "run the checks");
    tasks_complete(&list, 0);

    for (size_t i = 0; i < list.count; i++) {
        printf("[%c] %s\n", list.items[i].done ? 'x' : ' ', list.items[i].title);
    }
    printf("%zu open\n", tasks_open_count(&list));
    return 0;
}
