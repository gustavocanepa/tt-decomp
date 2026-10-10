extern "C" void *func_002A7618(void);
extern "C" void *func_00543708(void *arg0);
extern "C" char D_005BDF40[];

struct func_0026CF08_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *func_0026CF08(void *arg0)
{
    func_002A7618();
    ((struct func_0026CF08_arg0 *)arg0)->unk4 = D_005BDF40;
    return func_00543708((char *)arg0 + 0x10);
}
