//
// Created by Vasily Davydov on 9.1.2022.
//

#ifndef RSS_MANAGEMENT_MAINMENU_H
#define RSS_MANAGEMENT_MAINMENU_H
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <SP.h>

using namespace std;


string find_field(const  string &xml, const string& tag_name);

void menu(SP *ino);

string conf_and_go();

void display();

void showConf(const string& name, const string& prt, const string& bd, bool conf_f);

bool configFound();

void showLog();

void eraseLog();



#endif //RSS_MANAGEMENT_MAINMENU_H
