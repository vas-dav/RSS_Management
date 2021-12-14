class Counter {

public:
    Counter(int i, int up);
    void inc();
    int getInit();
    ~Counter() = default;

private:
    int init;
    int up_lim;

};
