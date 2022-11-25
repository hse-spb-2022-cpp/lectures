Data race is UB, even with `sleep`.

Do not use atomic, it's very hard if there is more than one variable (i.e. almost always)

std::cout is bytewise thread-safe: https://eel.is/c++draft/input.output#iostream.objects.overview-7
