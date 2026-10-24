/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Part { char pad[0xD4]; char mD4[4]; };
struct VEntry { short delta; short index; Part *(*fn)(void *, int); };
struct VObj { char pad[0x64]; VEntry *vtbl; };
struct Replay { char pad[0x1A20]; int count; };
static inline Part *vcall72(VObj *o, int id) {
    VEntry *e = &o->vtbl[72];
    return e->fn((char *)o + e->delta, id);
}
extern "C" void AutomobileControlRecord__Manager__save(void *, Replay *, int);
extern "C" void func_0033FCC8(VObj *o, Replay *r) {
    r->count = 2;
    AutomobileControlRecord__Manager__save(vcall72(o, 0x100)->mD4, r, 1);
    AutomobileControlRecord__Manager__save(vcall72(o, 0x101)->mD4, r, 1);
}
