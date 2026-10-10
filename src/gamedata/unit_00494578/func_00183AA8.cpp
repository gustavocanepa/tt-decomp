typedef int s32;

extern void func_002CD100(s32);
extern s32 func_001802A0(s32);

void func_00183AA8(s32 arg0, s32 arg1)
{
    s32 temp_v0;
    temp_v0 = func_001802A0(arg1);
    if (temp_v0 != 0) {
        func_002CD100(temp_v0);
    }
}
