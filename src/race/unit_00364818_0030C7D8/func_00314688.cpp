typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
struct T { char pad[0x26C]; u16 tbl[1]; };
struct S {
    char pad0[0x10];
    T *p10;
    char pad1[0x58A - 0x14];
    char f56A;
};
extern "C" u32 func_002E4520(S *a, s32 b);
extern "C" u32 func_00314688(S *o, s32 i) {
    T *t = o->p10;
    u16 *e = t->tbl + i;
    u32 v = *e;
    if (o->f56A == 1)
        v = func_002E4520(o, v);
    return v;
}
