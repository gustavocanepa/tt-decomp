/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Buf { int fd; int pad4; int pad8; };
struct StreamBuf { int pad0; int readPtr; int readEnd; };
struct Ios {
    StreamBuf *sb;      /* 0x00 */
    void *tie;          /* 0x04 */
    char pad8[8];
    unsigned long long flags; /* 0x10 */
    char pad18[2];
    u8 state;           /* 0x1A */
};
struct Stream { Ios *ios; };
extern "C" void *func_004E42B0(void *);
extern "C" int func_004E43E0(Stream *);
extern "C" int func_005757E0(Stream *is, int need) {
    Ios *ios = is->ios;
    if (ios->state) {
        ios->state |= 2;
        return 0;
    }
    if (ios->tie && (need == 0 || ios->sb->readEnd - ios->sb->readPtr < need))
        func_004E42B0(ios->tie);
    if (need == 0) {
        if ((int)(is->ios->flags & 1)) return func_004E43E0(is);
    }
    return 1;
}
