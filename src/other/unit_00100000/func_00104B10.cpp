typedef int s32;

extern "C" s32 func_00104B40(s32 arg0, s32 arg1, s32 arg2);
extern "C" s32 func_00104E30();

extern "C" s32 func_00104B10(s32 arg0)
{
    s32 s0 = arg0;
    s32 v0 = func_00104E30();
    return func_00104B40(s0, v0, 0);
}
