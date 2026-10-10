struct RaceDisplayObjectBase {
    char data[0x14];
    virtual ~RaceDisplayObjectBase();
    RaceDisplayObjectBase() __asm__("RaceDisplayObjectBase__structor_0");
};

/* Named after its constructor so that the call resolves. */
struct func_0035F430 {
    char data[0x24];
    func_0035F430();
};

struct RacePriusHybridDisplay : RaceDisplayObjectBase {
    int m18;
    int m1C;
    int m20;
    unsigned int m24;
    func_0035F430 parts[5];
    RacePriusHybridDisplay() __asm__("RacePriusHybridDisplay__structor_1");
    virtual ~RacePriusHybridDisplay();
};

RacePriusHybridDisplay::RacePriusHybridDisplay() {
    m18 = 0;
    m1C = 0;
    m20 = 0;
    m24 &= ~0xFF;
}
