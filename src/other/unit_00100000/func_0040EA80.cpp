typedef long long s64;

struct Obj {
    char pad0[0xF0];
    s64 unkF0;
};

extern "C" void func_0040EA08(s64 arg0);

extern "C" void func_0040EA80(Obj *arg0) {
    func_0040EA08(arg0->unkF0);
}
