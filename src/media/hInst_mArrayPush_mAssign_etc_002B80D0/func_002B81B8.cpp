extern "C" void *func_002B2290(void *arg0);
extern "C" void *func_002BC270(void *arg0);
extern "C" char D_005C6418[];

struct func_002B81B8_s0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *func_002B81B8(void *arg0)
{
    void *s0 = arg0;
    func_002B2290(s0);
    ((struct func_002B81B8_s0 *)s0)->unk4 = D_005C6418;
    return func_002BC270((char *)s0 + 0xC);
}
