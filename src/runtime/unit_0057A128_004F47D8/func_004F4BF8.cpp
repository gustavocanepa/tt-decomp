extern "C" void *func_004F4808(void);
extern "C" void *func_004AE9C0(void *arg0);
extern "C" char D_005DB6D8[];

struct func_004F4BF8_arg0 {
    char pad0[0x18];
    void *unk18;
};

extern "C" void *func_004F4BF8(void *arg0)
{
    func_004F4808();
    ((struct func_004F4BF8_arg0 *)arg0)->unk18 = D_005DB6D8;
    return func_004AE9C0((char *)arg0 + 0x1C);
}
