typedef int s32;

struct Obj {
    char pad[0x230];
    s32 unk230;
    s32 unk234;
};

extern "C" void func_002C2F90(void *arg0, void *arg1, s32 arg2);

extern "C" void func_002CCF40(Obj *arg0, void *arg1) {
    func_002C2F90((char *)arg0 + 0xCC, arg1, 0);
    arg0->unk230 = 0;
    arg0->unk234 = 0;
}
