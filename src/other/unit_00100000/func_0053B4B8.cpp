typedef int s32;

struct Obj {
    char pad[0xC8];
    s32 unk9C;
};

extern "C" void func_0053B4B8(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x80;
    v = v | (temp << 7);
    arg0->unk9C = v;
}
