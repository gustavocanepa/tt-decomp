typedef int s32;

extern s32 func_00485450(s32);
extern void func_00485BB8(s32);

void func_002495D0(s32 arg0)
{
    s32 temp_s0;
    
    temp_s0 = arg0 + 0x5B8;
    if (func_00485450(temp_s0) != 0) {
        func_00485BB8(temp_s0);
    }
}
