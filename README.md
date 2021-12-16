# RoomStateSensor
### Explanation:
This project was made for one reason: to notify my rommmate about my availability. I built an easy circuit using Elegoo Uno and several sensors and  thought to present it to my teacher as an cplusplus project, which later on was declined as it is. Teacher, on the other hand suggested to add several features 
to it, so it would be acceptable for the particular course. 

### Features: 
#### Controller side: 
- User has for states of a room: **Busy;Home;Come;Away** (Can be found in the [file](RoomyState/lcd.cpp))
- Each state is controllable with a **button** included in the circuit
> When the **button** is pressed, it communicates with a [**Counter class**](RoomyState/Counter.h), which has an overflow feature making it really scalable for more 
states added in future. 
- Indicator LED of a particular state for tail-end with a button
- Indicating the current tempreature and humidity
#### Pi side:
- Reading the change of the state coming from an Arduino connected via USB
- Loading your configuration **JSON** file, see example [here]() //add later
- Logging the state change during the program is running, see example [here]() //add later 
- Sending the log file after closing the program with a telegram bot **NOT IMPLEMENTED**
### Communication:
Running the program on pi, will initialize the configuration file and check if the device is connected to the port or not. In case the Controller is connected to Pi, the Pi will send a hello signal to Controller, if the Controller is able to read the signal, it will respond to the Pi with the current state. Pi will create a new `log_file` (if user doesn't have one already) with a configuration data and will document the activity until the program is stopped manually or just exitted the scanning mode. 
#### The program will have the following menu:
| Choice | Functionality |
| ------ | ------ |
| Read Configuration | Read the configuration from the file |
| Enter Configuration Manually | If you don't have a config_file, the configuration can be entered manually |
| Enter Communication Mode | Logging the activity to the file every time the state changes. |
| Exit | Exits the program |

> **Read Configuration** requires a JSON file with a name of the device, port number and a communication speed (baud)

> **Enter Configuration Manually** allows to enter mentioned information manually without a config_file

> **Enter Communication Mode** requires a configuration flag to enter. Can't be entered without a configuration. After the device is initialized, reads the initial state and writes/appends to the `log_file`. The mode closes the file and reopens it for appending only when the state has been changed again. This is made for the sake of autosaving the data. Mode can be ended with a press of 'q' character. The scanning is being run on a detached thread. 
