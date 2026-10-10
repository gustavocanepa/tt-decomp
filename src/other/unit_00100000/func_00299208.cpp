typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_00298F48(Guard *);
extern "C" void func_00298EF0(Guard *, s32);

extern "C" void func_00299208(void) {
    Guard g;
    func_00298F48(&g);
    {
        VObj *o = g.p;
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x1D0);
        e->fn((char *)o + e->delta);
    }
    func_00298EF0(&g, 2);
}
