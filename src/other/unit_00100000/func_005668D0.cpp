typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00418C68(s32 arg0);

extern "C" s32 func_005668D0(Obj *arg0)
{
    return func_00418C68(arg0->unk4);
}
