typedef int s32;
typedef long s64;
struct Obj { s64 f0; s32 f8; s32 fC; };
struct Tmp { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; char pad[0xC]; };
extern "C" void func_00412368(void *);
extern "C" s32 func_0047DB20(Tmp *, char *, s32);
extern "C" s32 func_004A8368(const char *);
extern "C" int func_004A64A8(char *, unsigned, const char *, ...);
struct Ent { s64 id; char name[1]; };
extern Ent D_00585A30;
extern char D_005FCC40[];

extern "C" s32 func_00411ED0(Obj *self, s64 id) {
    if ((id >> 32) == 0x26) return 0;
    if (id == self->f0) return 1;
    Tmp t;
    const char *s = (const char *)&D_00585A30;
    s += 8;
    s32 n = func_004A8368(s);
    char *buf = (char *)__builtin_alloca(n + 0x16 + 0xF & ~0xF);
    func_004A64A8(buf, n + 0x16, D_005FCC40, s, id);
    func_00412368(self);
    func_0047DB20(&t, buf, 1);
    if (t.f0 == 9) return 0;
    s32 a = t.f10;
    s32 b = t.f8;
    self->f0 = id;
    self->fC = b;
    self->f8 = a;
    return 1;
}
