typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FD2B8(s32 arg0);

extern "C" s32 func_0051B288(Obj *arg0)
{
    return func_003FD2B8(arg0->unk10);
}
