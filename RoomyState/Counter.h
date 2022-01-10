#ifndef Counter_h
#define Counter_h

class Counter {

public:
    Counter(int i, int up);
    void inc();
    int getInit();
    void setInit(int i);
    ~Counter() = default;

private:
    int init;
    int up_lim;

};

#endif
