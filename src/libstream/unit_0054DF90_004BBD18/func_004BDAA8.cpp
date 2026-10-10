typedef int s32;

struct Obj {
    char pad0[0xC];
    s32 unkC;
};

extern "C" s32 func_004CDBE8(s32 arg0);

extern "C" s32 func_004BDAA8(Obj *arg0)
{
    return func_004CDBE8(arg0->unkC);
}
