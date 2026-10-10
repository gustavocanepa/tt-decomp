extern "C" void *func_002C0EB0(void *arg0);
extern "C" char D_005C5A10[];

extern "C" void func_002A7618(void *arg0)
{
    func_002C0EB0(arg0);
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = D_005C5A10;
}
