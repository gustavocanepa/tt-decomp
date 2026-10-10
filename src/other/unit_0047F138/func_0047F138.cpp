typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, void *); };
struct VObj { char pad[0xA4]; VEntry *vtbl; };
extern "C" VObj *func_0047F398(void *);

extern "C" s32 func_0047F138(void *self) {
    VObj *o = func_0047F398(self);
    VEntry *e = (VEntry *)((char *)o->vtbl + 0x88);
    return e->fn((char *)o + e->delta, self);
}
