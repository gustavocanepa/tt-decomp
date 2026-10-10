typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00201CF0(struct Buf00109C40 *arg0);
extern "C" void func_00202248(s32 arg0);
extern "C" void func_00201C98(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00201E78(void) {
    struct Buf00109C40 buf;

    func_00201CF0(&buf);
    func_00202248(buf.unk0);
    func_00201C98(&buf, 2);
}
