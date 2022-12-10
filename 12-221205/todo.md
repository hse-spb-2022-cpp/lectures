03-c-str: get rid of duplicated examples (esp. duplicated with the first reading of c-str)
04-c-resource-management: Add example of sqlite-like interface (does not return pointer, instead returns an error code)

Do not use json-c, as it is complicated stuff which includes `shared_ptr` semantics? Something `unique_ptr`-like with `clone` is better.
Maybe libcurl? Or some hashing? Both provide examples of creating an 'instance of a library' and very low-level stuff, which may be counterintuitive.
