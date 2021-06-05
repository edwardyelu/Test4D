#pragma once

namespace ParserJson
{

enum class JsonType
{
    JSTRING,
    JOBJECT,
    JARRAY,
    JBOOLEAN,
    JNUMBER,
    JNULL,
    JUNKNOWN
};

}  // namespace ParserJson
