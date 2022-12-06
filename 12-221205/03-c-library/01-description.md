C APIs may seem complicated. It is because:

1. They use C and fully manual resource management.
   E.g. no methods grouped for an object, functions are intermingled in docs, lots of void*, lack of `const`.
   E.g. a buffer is user-allocated and is two arguments: the pointer and the length.
2. They rarely interoperate with each other.
   E.g. there may be a "dynamic string/array" library and a separate
   "file reading"/"network sockets" library which only knows about C
   with fixed-size buffers.
3. They are very low-level for the domain, although there may be "convenience wrappers".
   Lots of options, all cases of the domain are covered.
   Any interface may be wrong, convoluted or both.
   E.g.: do not use these functions: https://www.openssl.org/docs/man1.1.1/man3/SHA256.html
4. There may be lots of "flags", bit-fiddling, data packing, little type checks.
   Not a beautiful `enum`, but just `int`/`long` (be careful) and a bunch of
   consts which you have to find in the code.
   E.g. `fopen("a.txt", "r")`, `printf("hello=%d", 123)`
   E.g. https://curl.se/libcurl/c/curl_easy_setopt.html
5. Anything can err, should be handled.
   In C++ we just don't think about it as much => surprising exceptions or silent failures (like with `iostream`).

How to use:

0. Try find library in C++, otherwise:
1. Try to find a "convenience wrapper" or "simple interface".
2. Try to find a full official example: https://curl.se/libcurl/c/example.html
3. DO NOT try to call random functions without reading docs/manpages.

Convention:

* (Almost) everything can be either zero-initialized with `memset` or have a dedicated initialization function.
* (Almost) everything can be copied/moved bytewise with `memcpy`.
* Memory and buffers are either:
  * Fully (de)allocated by the user (strings)
  * Fully (de)allocated by the library (see next example).
