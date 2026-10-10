extern "C" void *func_002A7618(void);
extern "C" void *func_004CAFB8(void *arg0);
extern "C" char D_005B0238[];

struct func_001D3728_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *func_001D3728(void *arg0)
{
    func_002A7618();
    ((struct func_001D3728_arg0 *)arg0)->unk4 = D_005B0238;
    return func_004CAFB8((char *)arg0 + 0x10);
}
