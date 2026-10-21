typedef int s32;
typedef unsigned int u32;

extern "C" void func_001C7430(char *arg0, s32 arg1, s32 arg2)
{
    u32 *cnt = (u32 *)(arg0 + 0x390);
    u32 n = *cnt;

    *(s32 *)((char *)cnt + 0x88) = arg1;
    if (n < 0x10) {
        arg0 += n * 4;
        *(s32 *)(arg0 + 0x394) = arg2;
        *cnt = n + 1;
    }
}
