typedef int s32;

struct S00266408 {
    char pad0[0xB0];
    s32 unk9C;
};

extern "C" void func_0020E5E0(struct S00266408 *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unk9C;
    v = v & ~0x40;
    v = v | (temp << 6);
    arg0->unk9C = v;
}
