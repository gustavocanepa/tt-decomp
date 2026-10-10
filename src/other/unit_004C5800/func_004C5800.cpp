extern "C" void *func_004C5188(void *arg0);
extern "C" char D_005DB278[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void func_004C5800(void *arg0)
{
    func_004C5188(arg0);
    ((S003F15B0 *)arg0)->unk64 = D_005DB278;
}
