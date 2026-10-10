typedef int s32;

struct Obj {
    char pad[0x958];
    s32 unk958;
};

extern "C" void func_0033BA08(void *arg0);

extern "C" void func_00386E88(void *arg0, struct Obj *arg1) {
    func_0033BA08(arg0);
    arg1->unk958 = 1;
}
