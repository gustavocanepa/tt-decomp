typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001E6480(struct Buf00109C40 *arg0);
extern "C" void func_001E8E28(s32 arg0);
extern "C" void func_001E6428(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001E6BF0(void) {
    struct Buf00109C40 buf;

    func_001E6480(&buf);
    func_001E8E28(buf.unk0);
    func_001E6428(&buf, 2);
}
