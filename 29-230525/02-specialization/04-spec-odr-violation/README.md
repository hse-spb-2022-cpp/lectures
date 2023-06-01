Specializations should be the same in all translation units!
ODR otherwise, like here.

If you add `inline` to function definitions, it becomes silent
https://stackoverflow.com/questions/45120323/why-c-linker-is-silent-about-odr-violation

Moral: do not specialialize in different headers/translation units.
