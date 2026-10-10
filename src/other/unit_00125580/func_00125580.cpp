typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00123F58(struct Buf00109C40 *arg0);
extern "C" void func_00126768(s32 arg0);
extern "C" void func_00123F00(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00125580(void) {
    struct Buf00109C40 buf;

    func_00123F58(&buf);
    func_00126768(buf.unk0);
    func_00123F00(&buf, 2);
}
