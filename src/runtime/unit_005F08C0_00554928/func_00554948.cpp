extern "C" void *RaceBasic__structor_0(void *arg0);
extern "C" char D_005CDA10[];

struct S003F15B0 {
    char pad[0x64];
    void *unk64;
};

extern "C" void func_00554948(void *arg0)
{
    RaceBasic__structor_0(arg0);
    ((S003F15B0 *)arg0)->unk64 = D_005CDA10;
}
