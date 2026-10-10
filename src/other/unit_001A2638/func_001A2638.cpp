typedef int s32;

struct Obj {
    char pad0[0xC];
    s32 unkC;
};

extern "C" s32 func_0048A320(s32 arg0);

extern "C" s32 func_001A2638(Obj *arg0)
{
    return func_0048A320(arg0->unkC);
}
