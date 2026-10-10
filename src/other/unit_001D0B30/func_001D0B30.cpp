typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001D0060(struct Buf00109C40 *arg0);
extern "C" void func_001D2050(s32 arg0);
extern "C" void func_001D0008(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001D0B30(void) {
    struct Buf00109C40 buf;

    func_001D0060(&buf);
    func_001D2050(buf.unk0);
    func_001D0008(&buf, 2);
}
