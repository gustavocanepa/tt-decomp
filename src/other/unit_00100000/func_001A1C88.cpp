typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_004B9648(s32 arg0);

extern "C" s32 func_001A1C88(Obj *arg0)
{
    return func_004B9648(arg0->unk4);
}
