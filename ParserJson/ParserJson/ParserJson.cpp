// ParserJson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include "Parse.h"

using namespace std;

int main()
{
    ifstream in("data.json");
    string str = "";
    string tmp;
    while (getline(in, tmp)) str += tmp;
    ParserJson::jValue v = ParserJson::Parse::parse(str);
    cout << v.to_string() << endl;

    // you can use jute::Parse::parse_file("data.json")

    cout << " ------ " << endl;
    cout << v["examples"][0]["attr"][0]["value"].as_string() << endl;
    if (v["examples"][1]["mixed"][5][1][1].as_bool())
    {
        cout << v["examples"][1]["pie"].as_double() << endl;
        cout << v["examples"][2].to_string() << endl;
    }
}
