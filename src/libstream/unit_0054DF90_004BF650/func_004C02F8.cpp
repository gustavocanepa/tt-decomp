struct Clock {
    unsigned char stat;
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char pad;
    unsigned char day;
    unsigned char month;
    unsigned char year;
};

struct Tm {
    int data[4];
};

extern "C" void func_004B7488(Tm *tm, const Clock *clock);
extern "C" long long func_004AF8E8(Tm *tm);
extern "C" int func_004DAF98(Clock *clock);
extern long long D_00598810;

extern "C" void func_004C02F8(void) {
    Clock clock;
    clock.stat = 0;
    clock.second = 0;
    clock.minute = 0;
    clock.hour = 9;
    clock.pad = 0;
    clock.day = 2;
    clock.month = 1;
    clock.year = 1;
    Tm base;
    func_004B7488(&base, &clock);
    long long t0 = func_004AF8E8(&base);
    func_004DAF98(&clock);
    Tm now;
    func_004B7488(&now, &clock);
    long long t1 = func_004AF8E8(&now);
    D_00598810 = t1 - t0;
}
