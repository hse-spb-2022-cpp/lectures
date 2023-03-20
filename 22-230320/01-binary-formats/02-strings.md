Strings are even worse: there are no characters.

* Simple encodings: single byte per "character": 1251, 866, KOI8-R, https://neolurk.org/wiki/%D0%91%D0%9D%D0%9E%D0%9F%D0%9D%D0%AF

* Unicode: there are "code points" which are *not characters* and may alter each other:
  https://manishearth.github.io/blog/2017/01/14/stop-ascribing-meaning-to-unicode-code-points/
  * Code units ~ bytes
  * Code points ~ very simple characters, sometimes, not really
  * Grapheme clusters ~ characters, not really
* E.g. emojis are typically multiple code points.
  * 🇦🇺
  * https://string-functions.com/reverse.aspx
  * Reversed "[flag A][flag U]" (Australian flag) results in "[flag U][flag A]" (Ukranian flag)
  * https://www.youtube.com/watch?v=sTzp76JXsoY
* Same character may have different meaning depending on the language.
  * Turkish i is small "latin i", but it's capital is İ, not I. There is also ı, not i.
  * German eszett (ß) is a single codepoint which should be treated as "ss" when sorting.
  * https://youtu.be/mYhBS_4DoMA
  * https://tonsky.me/blog/emoji/
* There may be multiple ways to encode the same symbol: "ё" is both a code point, and "е"+"with dots" (two codepoints).

* There is no "canonical" representation of a string, it's *always* encoded somehow.

Most popular encoding nowadays: UTF-8

* Exactly ASCII for Latin.
* Multiple bytes per non-Latin code point.
* Python and Rust explicitly separate "string ~ sequence of Unicode codepoints" (`str`) and "sequence of bytes" (`bytes`)

Legacy:

* `const char*` and `std::string` may be anything
* `const wchar_t*` and `std::wstring` may be UTF-16 or something else using two bytes as code units
* You *have to* know the encoding. Somehow.
