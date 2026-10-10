typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001F0C00(struct Buf00109C40 *arg0);
extern "C" void func_001F2B58(s32 arg0);
extern "C" void func_001F0BA8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001F1748(void) {
    struct Buf00109C40 buf;

    func_001F0C00(&buf);
    func_001F2B58(buf.unk0);
    func_001F0BA8(&buf, 2);
}
