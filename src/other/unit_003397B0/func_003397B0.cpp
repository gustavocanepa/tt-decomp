extern "C" void *func_00339090(void *arg0);
extern "C" char D_005CB218[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void func_003397B0(void *arg0)
{
    func_00339090(arg0);
    ((S003F15B0 *)arg0)->unk64 = D_005CB218;
}
