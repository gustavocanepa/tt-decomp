typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00251678(struct Buf00109C40 *arg0);
extern "C" void func_00258178(s32 arg0);
extern "C" void func_00251620(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_002522E8(void) {
    struct Buf00109C40 buf;

    func_00251678(&buf);
    func_00258178(buf.unk0);
    func_00251620(&buf, 2);
}
