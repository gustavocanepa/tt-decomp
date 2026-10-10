typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" s32 func_00357310(const char *arg0);

extern "C" void func_0039E9A8(struct Obj *arg0) {
    arg0->unk10 = func_00357310("gear_base");
}
