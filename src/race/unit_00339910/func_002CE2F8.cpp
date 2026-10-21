typedef int s32;

struct Elem { s32 a, b; };
struct Vec { char pad[4]; Elem *begin; Elem *end; };

extern "C" void free(void *) throw();
extern "C" void func_0050E1A8(void *) throw();
extern "C" void func_0043D510(Elem *);
extern "C" void func_0034E800(void *, s32);
extern "C" void RaceBGMPS2__structor_1(void *, s32);
extern "C" void func_0036C2A8(void *, s32);
extern "C" void func_00396260(void *, s32);
extern "C" void func_00338F28(void *, s32);
extern "C" void RigidBodyManager__structor_1(void *, s32);
extern "C" void ParticleManager__structor_1(void *, s32);
extern "C" void func_002E13C8(void *, s32);
extern "C" void func_003900C8(void *, s32);
extern "C" void func_00339EC8(void *, s32);

extern char D_005C8BB0[];

extern "C" void func_002CE2F8(char *arg0, s32 arg1) {
    Elem *dead[4];
    *(char **)(arg0 + 0x64) = D_005C8BB0;
    free(*(void **)(arg0 + 0xE58));
    free(*(void **)(arg0 + 0xE54));
    void *p = *(void **)(arg0 + 0xE478);
    dead[0] = (Elem *)p;
    if (p) free(p);
    Vec *v = (Vec *)(arg0 + 0xE418);
    Elem *b = v->begin;
    Elem *end = v->end;
    Elem *e = b;
    dead[0] = b;
    if (e != end) {
        do {
            func_0043D510(e);
            e++;
        } while (e != end);
    }
    if (v->begin) free(v->begin);
    func_0034E800(arg0 + 0xE220, 2);
    RaceBGMPS2__structor_1(arg0 + 0xD038, 2);
    func_0036C2A8(arg0 + 0xD018, 2);
    func_00396260(arg0 + 0x36C0, 2);
    func_00338F28(arg0 + 0x36BC, 2);
    RigidBodyManager__structor_1(arg0 + 0x3680, 2);
    ParticleManager__structor_1(arg0 + 0x32D0, 2);
    func_002E13C8(arg0 + 0x3290, 2);
    func_003900C8(arg0 + 0xE60, 2);
    func_00339EC8(arg0, 0);
    if (arg1 & 1) func_0050E1A8(arg0);
}
