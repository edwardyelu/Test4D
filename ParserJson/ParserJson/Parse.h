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

class Parse
{
private:
    enum token_type
    {
        UNKNOWN,
        STRING,
        NUMBER,
        CROUSH_OPEN,
        CROUSH_CLOSE,
        BRACKET_OPEN,
        BRACKET_CLOSE,
        COMMA,
        COLON,
        BOOLEAN,
        NUL
    };

    struct token;
    static bool is_whitespace(const char c);
    static int next_whitespace(const std::string& source, int i);
    static int skip_whitespaces(const std::string& source, int i);

    static std::vector<token> tokenize(std::string source);
    static jValue json_parse(std::vector<token> v, int i, int& r);

public:
    static jValue parse(const std::string& str);
    static jValue parse_file(const std::string& str);
};

}  // namespace ParserJson
