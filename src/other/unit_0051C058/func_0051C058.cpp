typedef int s32;

struct Obj {
    char pad[0x10];
    void *unk10;
};

extern "C" int func_003FCD08(void *a0, void *a1);

extern "C" void func_0051C058(struct Obj *arg0) {
    func_003FCD08(arg0->unk10, 0);
}
