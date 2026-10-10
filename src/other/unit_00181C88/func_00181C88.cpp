typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001803E8(struct Buf00109C40 *arg0);
extern "C" void func_001832C0(s32 arg0);
extern "C" void func_00180390(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00181C88(void) {
    struct Buf00109C40 buf;

    func_001803E8(&buf);
    func_001832C0(buf.unk0);
    func_00180390(&buf, 2);
}
