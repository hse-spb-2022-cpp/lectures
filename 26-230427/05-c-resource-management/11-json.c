#include <assert.h>
#include <stdio.h>
#include <json-c/json.h>

int main() {
    const char *s1 = "{\"field\":\"value\",\"arr\":[1,2,3.5]}";
    const char *s2 = "[1,2,3.5]";
    printf("s1=%s, s2=%s\n", s1, s2);

    struct json_object *obj1 = json_tokener_parse(s1);
    struct json_object *obj2 = json_tokener_parse(s2);
    assert(obj1);
    assert(obj2);

    const char *str1 = json_object_to_json_string_ext(obj1, JSON_C_TO_STRING_PRETTY);  // char* is owned by `obj1`
    const char *str2 = json_object_to_json_string_ext(obj2, JSON_C_TO_STRING_PRETTY);  // char* is owned by `obj2`

    json_object_put(obj2);  // destructor
    json_object_put(obj1);  // destructor

    printf("obj1=%s\n", str1);  // UB
    printf("obj2=%s\n", str2);  // UB
}
