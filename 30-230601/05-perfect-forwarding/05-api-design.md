Perfect forwarding since C++11:

* Use perfect forwarding when your function only wants to pass some of its arguments to the next function.
  Not storing them anywhere. Maybe bit of reading.
* Perfect forwarding never copies anything, it only passes references.
  The complex syntax is to make sure "a value category is preserved", i.e. the correct lvalue/rvalue reference is chosen.
* Perfect forwarding does not inspect the function called. It adapts for the caller.

Alternative (or in C++03): everything is by-value. Use `std::ref`/`std::cref` with `std::reference_wrapper`.
Better suited when passing by reference is not "the default".
E.g. passing a reference to a new thread is dangerous:

```c++
void some_thread(std::vector<int> vec, int &x) { .... }
int y = 5;
std::thread t2(some_thread, create_vector(), std::ref(y));  // bad: temporary likely dies before the thread starts.
```
