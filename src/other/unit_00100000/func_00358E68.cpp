extern "C" void *func_003587C8(void *arg0);
extern "C" char D_005CFAD8[];

extern "C" void func_00358E68(void *arg0)
{
    func_003587C8(arg0);
    *(int *)((char *)arg0 + 0x8) = 0;
    *(void **)((char *)arg0 + 0x4) = D_005CFAD8;
}
