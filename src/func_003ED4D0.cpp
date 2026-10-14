typedef int s32;
typedef unsigned int u32;

struct Buf {
    char pad[1];
};

struct func_003ED4D0_arg0 {
    char pad0[0x85C];
    char pad1[0x90];
    s32 unk8EC;
    s32 unk8F0;
    s32 unk8F4;
};

extern s32 D_005855B0;
extern s32 D_005855B4;

extern "C" void func_0045A330(Buf *b, int c);
extern "C" void func_0045A3A8(Buf *b, unsigned int c);
extern "C" void func_0045A560(Buf *b, s32 a, s32 c);

extern "C" void func_003ED4D0(struct func_003ED4D0_arg0 *arg0) {
    if (arg0->unk8EC != 0) {
        Buf *t = (Buf *)((char *)arg0 + 0x85C);
        func_0045A3A8(t, (u32)0xFFE8);
        func_0045A3A8((Buf *)((char *)arg0 + 0x85C), (u32)0x2B);
        func_0045A560((Buf *)((char *)arg0 + 0x85C), D_005855B0, 8);
        func_0045A330((Buf *)((char *)arg0 + 0x85C), 0);
        func_0045A560((Buf *)((char *)arg0 + 0x85C), arg0->unk8EC, 0x20);
    }
    if (arg0->unk8F0 != 0 && arg0->unk8F4 > 0) {
        Buf *t2 = (Buf *)((char *)arg0 + 0x85C);
        func_0045A3A8(t2, (u32)0xFFE9);
        func_0045A3A8((Buf *)((char *)arg0 + 0x85C), (u32)(arg0->unk8F4 + 0xB));
        func_0045A560((Buf *)((char *)arg0 + 0x85C), D_005855B4, 8);
        func_0045A330((Buf *)((char *)arg0 + 0x85C), 0);
        func_0045A560((Buf *)((char *)arg0 + 0x85C), arg0->unk8F0, arg0->unk8F4);
    }
}
