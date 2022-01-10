//
// Created by Vasily Davydov on 5.1.2022.
//

#ifndef RSS_MANAGEMENT_SP_H
#define RSS_MANAGEMENT_SP_H
#include "SerialPort.h"
#include "RSS_Parser.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include <thread>
#include <future>
#include <ctime>

//usleep for 1700000

class SP {
public:
    SP(const std::string& device_location_path,  int baudRate);
    bool init();
    void readMode();
    ~SP() = default;
    void openOrCreateLog();
    void closeLog();


private:
    std::vector<std::string> filenames = {"Log_File.txt"};
    std::ofstream log;
    int serialSpeed;
    bool initDATA();
    void infiniteRead(std::future<void> &future);
    int file_dest;
};


#endif //RSS_MANAGEMENT_SP_H
