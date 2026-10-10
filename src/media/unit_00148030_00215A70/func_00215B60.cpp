extern "C" void *func_001CE6A8(void *arg0);
extern "C" char D_005B3FC0[];

extern "C" void func_00215B60(void *arg0)
{
    func_001CE6A8(arg0);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = D_005B3FC0;
}
