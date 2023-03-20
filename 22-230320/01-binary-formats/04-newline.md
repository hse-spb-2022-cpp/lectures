`\n` in C++ - number 10.

Windows: newline: number 13 ('\r'), number 10 ('\n').
  Carriage return + new line, like in typewriter
Linux, modern macOS: number 10.
Old macOS: number 13.

C++, Python...:
File in "text mode": replace 13 with: 13 or 13+10 or 10.
File in "binary mode": write 13 as-is

Why:
https://xkcd.com/927/
https://xkcd.ru/927/
