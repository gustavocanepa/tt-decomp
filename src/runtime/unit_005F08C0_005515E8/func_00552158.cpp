typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x8C];
    s32 unk8C;
};

extern "C" void func_00552158(Obj *arg0, f32 arg1) {
    char *p = (char *)arg0 + arg0->unk8C * 0x44;
    *(f32 *)(p + 0x3C) = arg1;
}
