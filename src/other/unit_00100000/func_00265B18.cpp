typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002655D8(struct Buf00109C40 *arg0);
extern "C" void func_00266228(s32 arg0);
extern "C" void func_00265580(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00265B18(void) {
    struct Buf00109C40 buf;

    func_002655D8(&buf);
    func_00266228(buf.unk0);
    func_00265580(&buf, 2);
}
