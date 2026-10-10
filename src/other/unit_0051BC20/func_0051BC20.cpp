typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FCF50(s32 arg0);

extern "C" s32 func_0051BC20(Obj *arg0)
{
    return func_003FCF50(arg0->unk10);
}
