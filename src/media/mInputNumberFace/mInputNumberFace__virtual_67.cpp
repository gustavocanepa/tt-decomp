typedef int s32;

struct Obj002A4F30 {
    char pad0[0x108 + 40];
    s32 unk108;
    char pad1[0x144 - 0x108 - 4 - 40];
    s32 unk11C;
};

extern "C" void func_0020B378(void);
extern "C" void func_0020D7F0(struct Obj002A4F30 *arg0, s32 arg1);

extern "C" void mInputNumberFace__virtual_67(struct Obj002A4F30 *arg0) {
    struct Obj002A4F30 *s0 = arg0;

    func_0020B378();
    func_0020D7F0(s0, 0);
    s0->unk11C = s0->unk108;
}
