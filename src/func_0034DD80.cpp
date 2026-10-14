typedef int s32;
extern "C" void func_0046F0F8(s32 a);
extern "C" void func_00473A08(s32 a, s32 b, void *c);
extern "C" void func_00473AD0(s32 a, void *b);
extern "C" void func_00478C98(s32 a);
extern char D_005F4188[];
struct ObjA { char pad0[0x10]; s32 unk10; };
extern "C" void func_0034DD80(ObjA *arg0) {
    s32 i = 0;
    s32 s1 = 0x65;
    char *s0 = (char *)arg0;
    func_00473AD0(0, D_005F4188);
    do {
        s32 mask = 1 << (i + 0xB);
        i++;
        if (arg0->unk10 & mask) {
            func_0046F0F8(s1);
            func_00473A08(s1, 0xD, s0 + 0xAD0);
            func_00473A08(s1, 0, s0 + 0xAE0);
            func_00473A08(s1, 1, s0 + 0xAF0);
            func_00473A08(s1, 4, s0 + 0xB00);
        } else {
            func_00478C98(s1);
        }
        s0 += 0x50;
        s1++;
    } while (i < 4);
}
