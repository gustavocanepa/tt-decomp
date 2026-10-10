typedef int s32;

struct S003A4D80 {
    char pad0[0x24];
    s32 unk24;
};

extern "C" void func_004F7B74(void *arg0);

extern "C" void func_0035A108(struct S003A4D80 *arg0, s32 arg1, s32 arg2) {
    arg0->unk24 = arg2;
    func_004F7B74((char *)arg0 + 0x70);
}
