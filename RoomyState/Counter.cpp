#include "Counter.h"

void Counter::inc() {
    if(init >= up_lim){
        init = 0;
    } else{
        ++init;
    }
}

int Counter::getInit(){
  return this->init;
}

Counter::Counter(int i, int up) {
    up_lim = up;
    if(i > up){
        init = up;
    }else if(i < 0){
        init = 0;
    }else{
        init = i;
    }

}

void Counter::setInit(int i){
  init = i;
}
