#ifndef B_H_
#define B_H_

// .h instead of .hpp because compatible with C. My personal tradition.

#ifdef __cplusplus
extern "C" {
#endif

int my_main(void);  // Remember to say "no arguments" in C! It's compatible with C++

#ifdef __cplusplus
}
#endif

#endif  // B_H_
