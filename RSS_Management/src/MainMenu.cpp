//
// Created by Vasily Davydov on 9.1.2022.
//

#include "MainMenu.h"
using std::__fs::filesystem::exists;

string find_field(const string &xml, const string& tag_name)
{
    string start, end, xml_string("not found");
    size_t first_point, second_point, diff;
    //TAG manipulation
    start = "<" + tag_name + ">";
    end = "</" + tag_name + ">";
    //Looking for TAG
    first_point = xml.find(start);
    if (first_point != string::npos){
        second_point = xml.find(end);
        if (second_point != string::npos){
            diff = second_point - (first_point + start.length());
            xml_string = xml.substr(first_point + start.length(), diff);
            return xml_string;
        }
    }
    return xml_string;
}

void display(){
    cout << "MAIN MENU" << endl;
    cout << "1. Show LOG_FL" << endl;
    cout << "2. Go in Read mode" << endl;
    cout << "3. Run device without reading" << endl;
    cout << "4. Erase LOG_FL" << endl;
    cout << "0. Exit" << endl;
}

void menu(SP *ino){

    int ch = 2;
    while(ch != 0){
        display();
        cout << "Enter your choice:" << endl;
        cin >> ch;
        switch (ch) {
            case 0:
                cout << "Closing Program" << endl;
                break;
            case 1:
                showLog();
                break;
            case 2:
                ino->readMode();
                break;
            case 3:
                ino->init();
                break;
            case 4:
                eraseLog();
                break;
            default:
                cout << "Wrong choice, try again..." << endl;
                break;
        }
    }
}

string conf_and_go(){
    string page ("NaN"), line;
    if (configFound()){
        cout << "CONF_FL found" << endl;
        ifstream inputFile("config.xml");

        if (inputFile.is_open()){
            while (getline (inputFile, line)) {
                page.append(line);
                line.erase();
            }
        }else{
            cout << "CONF_FL can't be opened" << endl;
        }
        inputFile.close();
        return page;
    } else{
        cout << "CONF_FL not found..." << endl;
        cout << "Setting default configuration" << endl;
        return page;
    }
}

void showConf(const string& name, const string& prt, const string& bd, bool conf_f){
    if(conf_f){
        cout << "From CONF_FL:" << endl;
        cout << "Device name: " << name << endl;
        cout << "Port: " << prt << endl;
        cout << "Port speed: " << bd << endl;
    }else{
        cout << "Default Configs:" << endl;
        cout << "Device name: " << name << endl;
        cout << "Port: " << prt << endl;
        cout << "Port speed: " << bd << endl;
    }
}

bool configFound(){
    return exists("config.xml");
}

void showLog(){
    ifstream log;
    string line;
    log.open("Log_File.txt", ios::in);
    if (log.is_open()){
        while (getline (log, line)) {
            cout << line << endl;
            line.erase();
        }
    }else{
        cout << "LOG_FL is not created, run {readMode}" << endl;
    }
    log.close();
}

void eraseLog(){
    remove("Log_File.txt") == 0 ? cout << "LOG_FL deleted" << endl : cout << "File doesn't exist or there is an error" << endl;
}