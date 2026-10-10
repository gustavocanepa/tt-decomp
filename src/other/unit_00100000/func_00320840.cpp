typedef float f32;

struct Obj {
    char pad0[0xA80];
    f32 unk9C0;
    char pad1[0xA94 - 0xA80 - 4];
    f32 unk9D4;
};

extern "C" void func_0031A9C0(struct Obj *arg0);
extern "C" void func_00318718(void *arg0, f32 fparg0, f32 fparg1);

extern "C" void func_00320840(struct Obj *arg0) {
    func_0031A9C0(arg0);
    func_00318718((char *)arg0 + 0xF00, arg0->unk9C0, arg0->unk9D4);
}
