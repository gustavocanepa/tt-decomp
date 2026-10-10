typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001FCB58(struct Buf00109C40 *arg0);
extern "C" void func_002002C8(s32 arg0);
extern "C" void func_001FCB00(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001FD410(void) {
    struct Buf00109C40 buf;

    func_001FCB58(&buf);
    func_002002C8(buf.unk0);
    func_001FCB00(&buf, 2);
}
