/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_002FDB30(int, int, int);
extern "C" void *func_00386980(void *);
extern "C" void func_003864A0(char *self, int n) {
    char *p = *(char **)(self + 0x6c);
    *(int *)(p + 0xb0) = 0;
    *(int *)(p + 0xe8) = 0;
    int x = *(int *)(self + 0x70);
    func_002FDB30(x, 0, n);
    if (*(int *)((char *)func_00386980(self) + 0x1d0) == 0)
        func_002FDB30(x, 1, n);
}
