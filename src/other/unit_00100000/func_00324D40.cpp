typedef unsigned char u8;
typedef int s32;

struct Obj {
    char pad[0x294];
    u8 unk268;
    char pad2[4];
    u8 unk26D;
};

extern "C" u8 func_00324D40(Obj *arg0) {
    if (arg0->unk268 != 0) {
        return 0;
    }
    return arg0->unk26D;
}
