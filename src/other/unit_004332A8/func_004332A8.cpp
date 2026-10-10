typedef int s32;

struct Obj {
    char pad0[0xE4];
    s32 unkE4;
};

extern "C" s32 func_00433230(s32 arg0);

extern "C" s32 func_004332A8(Obj *arg0)
{
    return func_00433230(arg0->unkE4);
}
