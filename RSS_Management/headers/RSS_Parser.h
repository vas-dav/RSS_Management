//
// Created by Vasily Davydov on 7.1.2022.
//

#ifndef RSS_MANAGEMENT_RSS_PARSER_H
#define RSS_MANAGEMENT_RSS_PARSER_H
#include <string>
#include <iostream>
#include <ctime>
#include <vector>

class RSS_Parser {
public:
    RSS_Parser() = default;
    bool all_data(const std::string& data);
    std::string getTemp();
    std::string getHumid();
    std::string getState();
    std::string getTime();
    ~RSS_Parser() = default;

private:
    std::string temp;
    std::string humid;
    char state {'U'};
    std::string state_str;
    std::string time_n;
};


#endif //RSS_MANAGEMENT_RSS_PARSER_H
