struct T { int x[11]; };
struct Obj { char pad0[0x14]; int f14; char pad1[0xC]; T t; };
extern "C" int func_004A8268(const char *, const char *);
extern T D_005FA990;
extern T D_005FA9C0;
extern T D_005FA9F0;
extern char D_005FA0A8[];

extern "C" void func_003FD588(Obj *o, const char *name) {
    T *p = &D_005FA990;
    if (func_004A8268(name, D_005FA0A8) == 0) {
        p = &D_005FA9F0;
    } else if (o->f14 != 0) {
        p = &D_005FA9C0;
    }
    o->t = *p;
}
