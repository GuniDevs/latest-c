#include <stdio.h>
#include <string.h>

#include "tasks.h"

static int failures = 0;

#define CHECK(cond)                                                   \
    do {                                                              \
        if (!(cond)) {                                                \
            fprintf(stderr, "FAILED %s:%d: %s\n", __FILE__, __LINE__, #cond); \
            failures++;                                               \
        }                                                             \
    } while (0)

static void test_add_and_complete(void) {
    TaskList list;
    tasks_init(&list);
    CHECK(tasks_add(&list, "one") == 0);
    CHECK(tasks_add(&list, "two") == 1);
    CHECK(tasks_open_count(&list) == 2);
    CHECK(tasks_complete(&list, 0) == 0);
    CHECK(tasks_open_count(&list) == 1);
    CHECK(strcmp(list.items[1].title, "two") == 0);
}

static void test_rejects_bad_input(void) {
    TaskList list;
    tasks_init(&list);
    CHECK(tasks_add(&list, "") == -1);
    CHECK(tasks_add(&list, NULL) == -1);
    CHECK(tasks_complete(&list, 0) == -1);
    for (int i = 0; i < TASK_MAX; i++) {
        CHECK(tasks_add(&list, "x") == i);
    }
    CHECK(tasks_add(&list, "overflow") == -1);
}

int main(void) {
    test_add_and_complete();
    test_rejects_bad_input();
    if (failures == 0) {
        printf("all tests passed\n");
    }
    return failures == 0 ? 0 : 1;
}
