typedef int s32;
typedef unsigned short u16;

extern "C" void func_00434A88(u16 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 k = 0xFFFF;
    u16 *p;
    s32 v;

    p = (u16 *)((char *)arg0 + ((arg1 * 8 + arg2) * 2));
    v = *p + arg3;
    if (k < v) {
        v = k;
    }
    *p = (u16)v;
}
