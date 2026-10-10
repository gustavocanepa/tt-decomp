extern "C" void *func_002A7618(void);
extern "C" void *func_004026C8(void *arg0);
extern "C" char D_005A8818[];

struct func_0016B940_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *func_0016B940(void *arg0)
{
    func_002A7618();
    ((struct func_0016B940_arg0 *)arg0)->unk4 = D_005A8818;
    return func_004026C8((char *)arg0 + 0x10);
}
