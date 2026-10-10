typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0026E9C0(struct Buf00109C40 *arg0);
extern "C" void func_0026FDE8(s32 arg0);
extern "C" void func_0026E968(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0026F6C0(void) {
    struct Buf00109C40 buf;

    func_0026E9C0(&buf);
    func_0026FDE8(buf.unk0);
    func_0026E968(&buf, 2);
}
