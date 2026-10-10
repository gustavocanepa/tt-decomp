typedef unsigned char u8;

extern u8 D_005834C5;

struct Obj {
    char pad[0x1B8];
    u8 unk1B8;
};

extern "C" void func_0039EED0(struct Obj *arg0) {
    if (D_005834C5 != 0) {
        arg0->unk1B8 = arg0->unk1B8 & 0xC0;
        return;
    }
    arg0->unk1B8 = 0;
}
