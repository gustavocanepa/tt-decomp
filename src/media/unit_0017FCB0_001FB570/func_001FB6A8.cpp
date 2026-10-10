typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001FB238(struct Buf00109C40 *arg0);
extern "C" void func_001FBCD8(s32 arg0);
extern "C" void func_001FB1E0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001FB6A8(void) {
    struct Buf00109C40 buf;

    func_001FB238(&buf);
    func_001FBCD8(buf.unk0);
    func_001FB1E0(&buf, 2);
}
