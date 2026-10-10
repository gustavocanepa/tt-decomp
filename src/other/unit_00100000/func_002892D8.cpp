typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_00288E58(Guard *);
extern "C" void func_00288E00(Guard *, s32);

extern "C" void func_002892D8(void) {
    Guard g;
    func_00288E58(&g);
    {
        VObj *o = g.p;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x1D8);
        e->fn((char *)o + e->delta);
    }
    func_00288E00(&g, 2);
}
