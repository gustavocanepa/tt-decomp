extern "C" void func_0033A158(void *arg0, int arg1, int arg2);
extern "C" void func_0011FAD0(void *arg0);
extern "C" void func_0011FAE0(int arg0);
extern "C" void func_0010B458(const char *arg0);

struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *);
};

extern "C" void func_00113440(void *arg0) {
    void *s1 = *(void **)((char *)arg0 + 0x6C);
    *(int *)((char *)s1 + 0xDC) = 1;
    *(int *)((char *)arg0 + 0xE0C) = 1;
    func_0033A158(arg0, 4, 1);
    func_0011FAD0(arg0);
    func_0011FAE0(1);
    func_0010B458("quick-mt");
    func_0011FAD0(0);

    void *vtbl = *(void **)((char *)arg0 + 0x64);
    VEntry *entry = (VEntry *)((char *)vtbl + 0x2D0);
    entry->fn((char *)arg0 + entry->delta);

    *(int *)((char *)arg0 + 0xE0C) = 0;
    *(int *)((char *)s1 + 0xDC) = 0;
}
