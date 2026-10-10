extern "C" void *func_003595B0(void *arg0);
extern "C" char D_005D0B58[];

extern "C" void func_0035FD88(void *arg0) {
    void *s0 = arg0;
    func_003595B0(s0);
    *(int *)((char *)s0 + 0x6C) = 0;
    *(int *)((char *)s0 + 0x68) = 0;
    *(void **)((char *)s0 + 0x14) = D_005D0B58;
}
