/* __static_initialization_and_destruction_0 of one global with an inline constructor/destructor
   (vtable D_005DA470; the destructor chains to the base destructor func_0047BD78). */
struct Obj {
    void *vtbl;
};

extern Obj D_0076FC88;
extern char D_005DA470[];
extern "C" void func_0047BD78(Obj *self, int in_chrg) throw();

static inline void construct(Obj *const self) {
    self->vtbl = D_005DA470;
}

static inline void destruct(Obj *const self) {
    self->vtbl = D_005DA470;
    func_0047BD78(self, 0);
}

extern "C" void func_0047C480(int init, int prio) {
    if (prio == 0xFFFF && init == 1)
        construct(&D_0076FC88);
    if (prio == 0xFFFF && init == 0)
        destruct(&D_0076FC88);
}
