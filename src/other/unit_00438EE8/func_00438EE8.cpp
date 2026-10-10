typedef int s32;

extern "C" s32 func_00438F48(s32 arg0);
extern "C" s32 func_00438F50(s32 arg0, s32 arg1);

extern "C" s32 func_00438EE8(s32 arg0)
{
    s32 s0 = arg0;
    s32 v0 = func_00438F48(arg0);
    return func_00438F50(s0, v0);
}
