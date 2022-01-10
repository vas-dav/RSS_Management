//
// Created by Vasily Davydov on 7.1.2022.
//

#include "../headers/RSS_Parser.h"
using namespace std;

std::string RSS_Parser::getHumid() {
    return humid;
}

std::string RSS_Parser::getTemp() {
    return temp;
}

std::string RSS_Parser::getState() {
    switch(state){
        case 'H':
            state_str = "Currently Home";
            break;
        case 'A':
            state_str = "Not Home";
            break;
        case 'B':
            state_str = "Currently Busy";
            break;
        case 'C':
            state_str = "Come In!";
            break;
        default:
            state_str = "Undefined Behaviour";
            break;

    }
    return this->state_str;
}

bool RSS_Parser::all_data(const std::string& data) {
    char * str = new char [data.size() + 1];
    strncpy(str, data.c_str(), data.size());
    char * p = str;
    vector<bool> markers = {false, false, false};
    time_t create = std::time(nullptr);
    time_n = ctime(&create);

    for (int i = 0; i < 3; ++i) {
        p = std::strstr(p, "#") + 1;
        switch (i) {
            case 0:
                state = *p;
                markers[0] = true;
                break;
            case 1:
                temp = std::string(p, std::strstr(p, "#") - p);
                markers[1] = true;
                break;
            case 2:
                 humid = std::string(p, std::strstr(p, ";") - p);
                 markers[2] = true;
            default:
                break;
        }
    }
    delete[] str;
    if (markers[0] && markers[1] && markers[2]){
        return true;
    }

    return false;
}

std::string RSS_Parser::getTime() {
    return this->time_n;
}



