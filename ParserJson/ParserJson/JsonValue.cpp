#include "JsonValue.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

namespace ParserJson
{

string JsonValue::makesp(int d)
{
    string s = "";
    while (d--) s += "  ";
    return s;
}
string JsonValue::to_string_d(int d)
{
    if (type == JsonType::JSTRING) return string("\"") + svalue + string("\"");
    if (type == JsonType::JNUMBER) return svalue;
    if (type == JsonType::JBOOLEAN) return svalue;
    if (type == JsonType::JNULL) return "null";
    if (type == JsonType::JOBJECT)
    {
        string s = string("{\n");
        for (size_t i = 0; i < properties.size(); i++)
        {
            s += makesp(d) + string("\"") + properties[i].first + string("\": ")
                 + properties[i].second.to_string_d(d + 1) + string(i == properties.size() - 1 ? "" : ",")
                 + string("\n");
        }
        s += makesp(d - 1) + string("}");
        return s;
    }
    if (type == JsonType::JARRAY)
    {
        string s = "[";
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (i) s += ", ";
            s += arr[i].to_string_d(d + 1);
        }
        s += "]";
        return s;
    }
    return "##";
}
JsonValue::JsonValue()
{
    this->type = JsonType::JUNKNOWN;
}
JsonValue::JsonValue(JsonType tp)
{
    this->type = tp;
}

string JsonValue::to_string()
{
    return to_string_d(1);
}
JsonType JsonValue::get_type()
{
    return type;
}
void JsonValue::set_type(JsonType tp)
{
    type = tp;
}
void JsonValue::add_property(string key, JsonValue v)
{
    mpindex[key] = properties.size();
    properties.push_back(make_pair(key, v));
}
void JsonValue::add_element(JsonValue v)
{
    arr.push_back(v);
}
void JsonValue::set_string(string s)
{
    svalue = s;
}
int JsonValue::as_int()
{
    stringstream ss;
    ss << svalue;
    int k;
    ss >> k;
    return k;
}
double JsonValue::as_double()
{
    stringstream ss;
    ss << svalue;
    double k;
    ss >> k;
    return k;
}
bool JsonValue::as_bool()
{
    if (svalue == "true") return true;
    return false;
}
void* JsonValue::as_null()
{
    return NULL;
}
string JsonValue::as_string()
{
    return deserialize(svalue);
}
int JsonValue::size()
{
    if (type == JsonType::JARRAY)
    {
        return (int)arr.size();
    }
    if (type == JsonType::JOBJECT)
    {
        return (int)properties.size();
        ;
    }
    return 0;
}
JsonValue JsonValue::operator[](int i)
{
    if (type == JsonType::JARRAY)
    {
        return arr[i];
    }
    if (type == JsonType::JOBJECT)
    {
        return properties[i].second;
    }
    return JsonValue();
}
JsonValue JsonValue::operator[](string s)
{
    if (mpindex.find(s) == mpindex.end()) return JsonValue();
    return properties[mpindex[s]].second;
}

}  // namespace ParserJson
