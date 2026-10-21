/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { int f0; VEntry *vtbl; };
extern "C" void mTransition__panOutIn(Obj *, Obj *);
extern "C" void func_001C7410(int);
extern "C" int mBlockTransition__initialize_blocks(Obj *) throw();
extern "C" void func_0021A6A8(Obj *self, Obj *other) {
    mTransition__panOutIn(self, other);
    VEntry *e = &other->vtbl[75];
    e->fn((char *)other + e->delta);
    func_001C7410(1);
    mBlockTransition__initialize_blocks(self);
}
