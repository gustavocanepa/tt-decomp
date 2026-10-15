typedef int s32;
typedef unsigned short u16;

struct Obj0055DD88 {
    char pad0[8];
    void *unk8;
    char pad1[0x18 - 0xC];
    u16 unk18;
};

extern "C" void func_004C7820(void *dev, s32 port, s32 arg);

extern "C" void func_004C8920(struct Obj0055DD88 *arg0, s32 arg1) {
    s32 v = arg0->unk18;

    func_004C7820(arg0->unk8, v >= 0x18, arg1);
}
