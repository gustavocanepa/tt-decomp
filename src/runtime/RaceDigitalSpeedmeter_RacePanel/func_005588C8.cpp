typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x1C];
    s32 unk1C;
};

extern "C" void func_005588C8(Obj *arg0, u8 arg1) {
    arg0->unk1C = (arg0->unk1C & ~0xFF) | arg1;
}
