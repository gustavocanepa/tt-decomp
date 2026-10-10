typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001FCB58(struct Buf00109C40 *arg0);
extern "C" void func_00200158(s32 arg0);
extern "C" void func_001FCB00(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001FD3E0(void) {
    struct Buf00109C40 buf;

    func_001FCB58(&buf);
    func_00200158(buf.unk0);
    func_001FCB00(&buf, 2);
}
