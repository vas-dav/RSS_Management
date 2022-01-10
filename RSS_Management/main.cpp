#include <string>
#include "headers/SP.h"
#include "MainMenu.h"


int main() {

    string conf = conf_and_go();
    string prt = "/dev.tty.USB0", bd_rate = "9600";
    if (conf != "NaN") {
        prt = find_field(conf, "port");
        bd_rate = find_field(conf, "baudrate");
        showConf(find_field(conf, "name"), prt, bd_rate, true);
        SP device(prt, stoi(bd_rate));
        menu(&device);
    } else {
        showConf("Unknown", prt, bd_rate, false);
        SP def(prt, stoi(bd_rate));
        menu(&def);
    }


    return EXIT_SUCCESS;
}
