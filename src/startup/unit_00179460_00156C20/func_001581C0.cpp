struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { int unk0; VEntry *vt; };
extern "C" int D_00579AC4;
extern "C" void func_001581C0(void *, void *, Obj **arg2) {
    Obj *o = *arg2;
    VEntry *e = (VEntry *)((char *)o->vt + 0x68);
    D_00579AC4 = e->fn((char *)o + e->delta) != 0;
}
