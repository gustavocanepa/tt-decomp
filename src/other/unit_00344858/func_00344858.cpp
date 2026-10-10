typedef int s32;

struct Obj {
    s32 unk0;
};

extern "C" void func_0041BCD0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_00344858(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0041BCD0((char *)arg0 + 0x18, arg0->unk0, arg1, arg2, arg3);
}
