typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00128470(struct Buf00109C40 *arg0);
extern "C" void func_001324A8(s32 arg0);
extern "C" void func_00128418(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0012E0C8(void) {
    struct Buf00109C40 buf;

    func_00128470(&buf);
    func_001324A8(buf.unk0);
    func_00128418(&buf, 2);
}
