typedef int s32;

extern s32 func_00484A40(s32);
extern void func_00485BB8(s32);

void func_002494F0(s32 arg0)
{
    s32 temp_s0;
    
    temp_s0 = arg0 + 0x5B8;
    if (func_00484A40(temp_s0) != 0) {
        func_00485BB8(temp_s0);
    }
}
