struct RaceDisplayObjectBase {
    char data[0x14];
    virtual ~RaceDisplayObjectBase();
    RaceDisplayObjectBase() __asm__("RaceDisplayObjectBase__structor_0");
};

/* Named after its constructor so that the call resolves. */
struct func_0035E910 {
    char data[0x1C];
    func_0035E910();
    void fadein(float t) __asm__("AutomaticFader__fadein");
};

struct RaceValueDisplayBase : RaceDisplayObjectBase {
    unsigned int color0;
    unsigned int color1;
    int m20;
    int m24;
    func_0035E910 fader;
    unsigned char m44;
    unsigned char m45;
    RaceValueDisplayBase();
    virtual ~RaceValueDisplayBase();
    void setName(const char *name) __asm__("func_00359638");
};

extern const char D_005F55F8[];

RaceValueDisplayBase::RaceValueDisplayBase() : color0(0x80C8C8C8), color1(0x80B3B3B3), m20(0), m24(0) {
    m44 = 0;
    m45 = 0;
    setName(D_005F55F8);
    fader.fadein(0.0f);
}
