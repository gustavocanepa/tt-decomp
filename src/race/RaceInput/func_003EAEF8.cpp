typedef int s32;

extern "C" s32 func_003EAF60(s32 arg0);

extern "C" s32 func_003EAEF8(s32 arg0, s32 arg1)
{
    s32 s0 = arg1;
    return (func_003EAF60(arg0) & s0) != 0;
}
