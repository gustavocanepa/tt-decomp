typedef int s32;
typedef long long s64;

struct Info { s32 pad[5]; s32 m14; s32 pad2[0x1A]; };
struct Mgr { char pad[0x1E8]; s32 m1E0; };
struct Self { char pad[0x38]; s64 id; };
extern Mgr D_00585A30;
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Mgr *, s64, Info *);
extern "C" void func_00411D78(s32, s32);

extern "C" void func_0040DB60(Self *self) {
    Info info;
    Mgr *m = &D_00585A30;
    SPEC_DATABASE__DatabaseStorage__getRow(m, self->id, &info);
    func_00411D78(m->m1E0, info.m14);
}
