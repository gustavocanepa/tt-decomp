/* compiler: ee-gcc2.96-no-strict-aliasing */
struct CTA {
    char pad0[0x20];
    int unk20;
    union { float f; int i; } unk24;
    union { float f; int i; } unk28;
    char pad2C[0x10];
    int unk3C;
};
struct CTB { int unk0; char *vtbl; };
struct CTVEntry { short delta; short index; void (*fn)(void *); };
extern "C" void mTransition__panOut(void *);
extern "C" void func_001C7410(int);
extern "C" void func_0022B508(void *arg0, void *arg1) {
    CTA *a = (CTA *)arg0;
    CTB *b = (CTB *)arg1;
    mTransition__panOut(arg0);
    a->unk24.f = 0.0f;
    a->unk28.f = 0x1.999998p-4f;
    a->unk3C = 0;
    if ((a->unk20) == 0) {
        CTVEntry *e = (CTVEntry *)(b->vtbl + 0x258);
        e->fn((char *)b + e->delta);
    }
    func_001C7410(1);
}
