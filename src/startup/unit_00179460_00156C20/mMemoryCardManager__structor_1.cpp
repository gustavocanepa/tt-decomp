struct hObject {
    int m0;
    virtual ~hObject();
    hObject() __asm__("hObject__structor_0");
};

/* Named after its constructor so that the call resolves. */
struct func_001DCE88 {
    int a;
    int b;
    func_001DCE88();
};

struct Range {
    int lo;
    int hi;
    Range() : lo(0), hi(0) {}
};

struct mMemoryCardManager : hObject {
    int m8;
    int mC;
    func_001DCE88 m10;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    Range m2C;
    mMemoryCardManager(int a, int b);
    virtual ~mMemoryCardManager();
    void init(int a, int b) __asm__("func_00158D38");
};

mMemoryCardManager::mMemoryCardManager(int a, int b) : m18(0), m1C(0), m20(0), m24(0) {
    m28 = 0;
    init(a, b);
}
