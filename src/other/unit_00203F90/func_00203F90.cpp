typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002027E0(struct Buf00109C40 *arg0);
extern "C" void func_00206B88(s32 arg0);
extern "C" void func_00202788(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00203F90(void) {
    struct Buf00109C40 buf;

    func_002027E0(&buf);
    func_00206B88(buf.unk0);
    func_00202788(&buf, 2);
}
