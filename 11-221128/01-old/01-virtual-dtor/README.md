Typical inheritance for polymorphism:

1. There is a single base class with pure virtual functions.
2. It has a virtual destructor.
3. Everything is stored via smart pointers.
   Otherwise you know the exact type and don't need virtual functions/inheritance:
   ```
   Derived d;
   d.some_base_method();  // No need for virtual functions, non-virtual call.
   ```
