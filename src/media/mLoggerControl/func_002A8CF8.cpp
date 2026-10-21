/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { s32 x; char *vt; };
struct Handle { Obj *p; s32 pad[3]; };
struct VEntry { short delta; short index; void (*fn)(void *, s32, s32, s32); };
extern "C" void func_002A75A8(void *, s32) throw();
extern "C" void func_002A7A30(void *);
extern "C" void func_002A9580(void *, void *, s32);
extern "C" void func_002A8CF8(void *self, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handle h;
    func_002A7A30(&h);
    func_002A9580(self, &h, arg2);
    if (h.p) {
        VEntry *e = (VEntry *)(h.p->vt + 0xC0);
        e->fn((char *)h.p + e->delta, arg1, arg3, arg4);
    }
    func_002A75A8(&h, 2);
}
