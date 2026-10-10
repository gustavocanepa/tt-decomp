typedef int s32;

extern "C" s32 func_00385BB8(s32 arg0);
extern "C" void func_003C8610(s32 arg0);

extern "C" s32 func_003C8690(s32 arg0)
{
    s32 s0 = arg0;
    func_003C8610(s0);
    return func_00385BB8(s0);
}
