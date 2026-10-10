typedef int s32;
typedef long long s64;

struct Mgr {
    char pad[0x1E8];
    s32 f1E0;
};

struct Obj {
    char pad[0x38];
    s64 key;
};

extern Mgr D_00585A30;
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Mgr *, s64, s32 *);
extern "C" void func_00411D78(s32, s32);

extern "C" void func_0040DBA0(Obj *self) {
    s32 buf[32];
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, self->key, buf);
    func_00411D78(D_00585A30.f1E0, buf[0]);
}
