### General Explanation:
This project was made for one reason: to notify my rommmate about my availability. I built an easy circuit using Elegoo Uno and several sensors and  thought to present it to my teacher as an cplusplus project, which later on was declined as it is. Teacher, on the other hand suggested to add several features 
to it, so it would be acceptable for the particular course. 

### Communication:
Running the program on a computer will read the configuration file and check if it is valid. In case the Controller is connected to Computer, the Computer will send a `#` message to Controller, if the Controller is able to read the signal, it will respond to the Computer. Computer will create a new `LOG_FL` (if user doesn't have one already) with a configuration data and will document the activity until the program is stopped manually or just exitted the **readMode**. 
#### The program will have the following menu:
| Choice | Functionality |
| ------ | ------ |
| Show LOG_FL | Show records |
| Go in Read mode | Logging the activity to the file every time the state changes. |
| Run device without reading | Running the device without reading |
| Erase LOG_FL | Deletes the LOG_FL |
| Exit | Exits the program |


> **Go in Read mode** Can't be entered without a configuration. If configuration file does not exit, program sets default values. The > first thing, it runs `initDATA()` and only then starts the `infiniteRead()`: 
```cpp
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
```
> Mode can be ended with a press of 'q' character. The scanning is being run on a detached thread. 

[**RSS_Parser.cpp**](RSS_Management/src/RSS_Parser.cpp) class is made only for validating the data incoming from Microcontroller, since the incoming format is:
> `#[state]#[temp]#[humid];`. 

[**SP.cpp**](RSS_Management/src/SP.cpp) class is made out using the library `SerialPort` linked below and modified it to a class with own functionality. 

