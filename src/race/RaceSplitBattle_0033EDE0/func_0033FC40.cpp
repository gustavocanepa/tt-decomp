/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Part { char pad[0xD4]; char mD4[4]; };
struct VEntry { short delta; short index; Part *(*fn)(void *, int); };
struct VObj { char pad[0x64]; VEntry *vtbl; };
static inline Part *vcall72(VObj *o, int id) {
    VEntry *e = &o->vtbl[72];
    return e->fn((char *)o + e->delta, id);
}
extern "C" char *AutomobileControlRecord__Manager__load(void *, char *, int);
extern "C" void func_0033FC40(VObj *o, char *r) {
    char *p = r + 0x1A24;
    p = AutomobileControlRecord__Manager__load(vcall72(o, 0x100)->mD4, p, 1);
    AutomobileControlRecord__Manager__load(vcall72(o, 0x101)->mD4, p, 1);
}
