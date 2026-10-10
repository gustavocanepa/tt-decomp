typedef int s32;

struct S;

extern "C" s32 func_001324D8(S *arg0);
extern "C" s32 func_00408B58(s32 arg0);
extern "C" s32 func_0040D1E8(s32 arg0);

extern "C" s32 func_001323F0(S *arg0)
{
    s32 v0 = func_001324D8(arg0);
    v0 = func_00408B58(v0);
    return func_0040D1E8(v0);
}
