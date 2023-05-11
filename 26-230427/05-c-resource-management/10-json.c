#include <assert.h>
#include <stdio.h>
#include <json-c/json.h>

int main() {
    const char *s = "{\"field\":\"value\",\"arr\":[1,2,3.5]}";

    struct json_object *obj = json_tokener_parse(s);
    // ~ shared_ptr<json_object>
    assert(obj);

    // for (auto [k, v] : obj)
    json_object_object_foreach(obj, k, v) {
        printf("%s --> %s\n", k, json_object_to_json_string_ext(v, JSON_C_TO_STRING_PRETTY));
    }

    json_object_put(obj);  // ~ destructor
}
