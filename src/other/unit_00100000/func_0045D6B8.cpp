typedef int s32;

extern "C" s32 func_004A8268(s32 arg0, s32 arg1);

extern "C" s32 func_0045D6B8(s32 arg0, s32 *arg1)
{
    return func_004A8268(arg0, *arg1);
}
