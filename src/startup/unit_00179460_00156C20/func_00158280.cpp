struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { int unk0; VEntry *vt; };
extern "C" int *func_0019A070();
extern "C" void func_00158280(void *, void *, Obj **arg2) {
    int *p = func_0019A070();
    Obj *o = *arg2;
    VEntry *e = (VEntry *)((char *)o->vt + 0x68);
    *p = e->fn((char *)o + e->delta) != 0;
}
