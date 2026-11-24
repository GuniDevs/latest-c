# c-sample-project

A small C project (task list library, demo app and tests) built with CMake. It has no outside libraries, so it builds
on a clean machine.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/task_app
```
