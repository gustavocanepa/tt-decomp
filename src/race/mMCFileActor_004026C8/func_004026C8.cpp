extern "C" void *func_00400D68(void *arg0);
extern "C" void *func_00412908(char *arg0);
extern "C" char D_005D9420[];

struct func_004026C8_s0 {
    void *unk0;
};

extern "C" void *func_004026C8(void *arg0)
{
    void *s0 = arg0;
    func_00400D68(s0);
    ((struct func_004026C8_s0 *)s0)->unk0 = D_005D9420;
    return func_00412908((char *)s0 + 0x4);
}
