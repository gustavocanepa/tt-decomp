extern "C" void func_0033A158(void *arg0, int arg1, int arg2);
extern "C" void func_0011FAD0(void *arg0);
extern "C" void func_0011FAE0(int arg0);
extern "C" void func_0010B458(const char *arg0);

struct VEntry {
    short delta;
    short pad;
    void (*fn)(void *);
};

struct func_00114E10_arg0 {
    char pad0[0x64];
    void *unk64;
    char pad68[0x4];
    void *unk6C;
    char pad70[0xD9C];
    int unkE0C;
};
struct func_00114E10_s1 {
    char pad0[0xDC];
    int unkDC;
};

extern "C" void func_00114E10(void *arg0) {
    void *s1 = ((struct func_00114E10_arg0 *)arg0)->unk6C;
    ((struct func_00114E10_s1 *)s1)->unkDC = 1;
    ((struct func_00114E10_arg0 *)arg0)->unkE0C = 1;
    func_0033A158(arg0, 4, 1);
    func_0011FAD0(arg0);
    func_0011FAE0(1);
    func_0010B458("quick-mt");
    func_0011FAD0(0);

    void *vtbl = ((struct func_00114E10_arg0 *)arg0)->unk64;
    VEntry *entry = (VEntry *)((char *)vtbl + 0x2D0);
    entry->fn((char *)arg0 + entry->delta);

    ((struct func_00114E10_arg0 *)arg0)->unkE0C = 0;
    ((struct func_00114E10_s1 *)s1)->unkDC = 0;
}
