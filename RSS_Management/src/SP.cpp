//
// Created by Vasily Davydov on 5.1.2022.
//

#include "../headers/SP.h"

using namespace std;
using std::__fs::filesystem::exists;

SP::SP(const std::string &device_location_path, const int baudRate) {

        filenames.push_back(device_location_path);
        this->serialSpeed = baudRate;
        file_dest = -1;

}

bool SP::initDATA() {
    ssize_t pass_in = 1; // initial value for the loop
    char init_buff = '\0';
    file_dest = openAndConfigureSerialPort(filenames.at(1).c_str(), this->serialSpeed);
    usleep(1700000); // Delay for microcontroller min. startup
    if (file_dest < 0) {
        return false;
    } else {
        if (writeSerialData("#", 1) == 1) {
            cout << "Data Request Sent" << endl <<  "Waiting for response... " << endl;
            usleep(1000000); // Delay for getting the response
            while (pass_in != 0) {
                read(file_dest, &init_buff, 1);
                if(init_buff == '$'){
                    cout << "Connection established" << endl;
                    return true;
                }else{
                    cout << "Wrong Response" << endl;
                    pass_in = 0;
                }
            }
        } else {
            cout << "Data Request Failed" << endl;
            return false;
        }
    }
    return false;
}

void SP::infiniteRead(future<void>& future) {
    ssize_t return_char;
    char data_buff = '\0';
    string data_tof;
    data_tof.erase();
    while (future.wait_for(chrono::milliseconds(1)) == future_status::timeout) {
        return_char = read(file_dest, &data_buff, 1);
        if (return_char != 0) {
            data_tof.push_back(data_buff);
            if(data_buff == ';'){
                RSS_Parser pcr;
                if (pcr.all_data(data_tof)){
                    data_tof.erase();
                    log << "State: {" << pcr.getState()
                    << "} Temp: {" << pcr.getTemp() <<
                    "C°} Humid: {" << pcr.getHumid() <<
                    "%} at: "<< pcr.getTime() <<endl;
                }
            }
        }

    }
}

void SP::openOrCreateLog() {
    string timestamp;
    if (__fs::filesystem::exists(filenames.at(0))){
        cout << "Opening LOG_FL" << endl;
        log.open(filenames.at(0), fstream::app);
        cout << "LOG_FL opened" << endl;
    }else{
        cout << "LOG_FL does not exist, creating..." << endl;
        time_t create = time(nullptr);
        timestamp = ctime(&create);
        log.open(filenames.at(0), fstream::app);
        cout << "LOG_FL created " << timestamp << endl;
        log << "LOG_FL created " << timestamp << endl;
    }





}



void SP::closeLog() {
    if(log.is_open()){
        log.close();
    }

}

void SP::readMode() {
    char c;
    if(initDATA()){
        openOrCreateLog();
        promise<void> exitSignal;
        future<void> future = exitSignal.get_future();
        thread r (&SP::infiniteRead, this, ref(future));
        r.detach();
        cout << "Press q to exit" << endl;
        do {
            cin >> c;
        }while(c != 'q');
        exitSignal.set_value();
        closeSerialPort();
        closeLog();
    }
}

bool SP::init() {
    file_dest = openAndConfigureSerialPort(filenames.at(1).c_str(), this->serialSpeed);
    usleep(2700000); // Delay for microcontroller min. startup
    if (file_dest < 0) {
        return false;
    } else {
            writeSerialData("#", 1);
            cout << "Device opened without reading" << endl;
            closeSerialPort();
            return true;
        }
}
