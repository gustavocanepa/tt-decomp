typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_004B9778(s32 arg0);

extern "C" s32 func_001A1CA0(Obj *arg0)
{
    return func_004B9778(arg0->unk4);
}
