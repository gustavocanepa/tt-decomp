typedef long long s64;

struct Obj {
    char pad0[0x100];
    s64 unk100;
};

extern "C" void func_0040EAA0(s64 arg0);

extern "C" void func_0040EB18(Obj *arg0) {
    func_0040EAA0(arg0->unk100);
}
