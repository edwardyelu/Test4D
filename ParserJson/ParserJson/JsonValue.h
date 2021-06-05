#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

#include "JsonType.h"

namespace ParserJson
{

class JsonValue
{
private:
    std::string makesp(int);
    std::string svalue;
    JsonType type;
    std::vector<std::pair<std::string, JsonValue> > properties;
    std::map<std::string, size_t> mpindex;
    std::vector<JsonValue> arr;
    std::string to_string_d(int);

public:
    JsonValue();
    JsonValue(JsonType);
    std::string to_string();
    JsonType get_type();
    void set_type(JsonType);
    void add_property(std::string key, JsonValue v);
    void add_element(JsonValue v);
    void set_string(std::string s);
    int as_int();
    double as_double();
    bool as_bool();
    void* as_null();
    std::string as_string();
    int size();
    JsonValue operator[](int i);
    JsonValue operator[](std::string s);
};

}  // namespace ParserJson
