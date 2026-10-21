/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Ev;
struct VEntryP { s16 delta; s16 index; void *(*fn)(void *); };
struct VEntry3 { s16 delta; s16 index; void (*fn)(void *, s32, s32, ...); };
extern char D_005ED310[], D_005ED318[], D_005ED330[];
struct Ev {
    char pad0[4];
    char *vtbl;
    char pad8[8];
    s32 u10;
    s32 u14;
};
extern "C" s32 func_0022F7B8(void *);
extern "C" s32 func_0022F7C8(void *);
extern "C" char *func_002A39C0(void *);
extern "C" void func_00526860(const char *, ...);
extern "C" s32 func_002343D0(struct Ev *self) {
    func_00526860(D_005ED310);
    VEntryP *e = (VEntryP *)(self->vtbl + 0x58);
    func_00526860(D_005ED318, func_002A39C0(e->fn((char *)self + e->delta)), self->u14, self->u10);
    if (func_0022F7C8(self)) {
        s32 s0 = func_0022F7B8(self);
        s32 r2 = func_0022F7C8(self);
        VEntry3 *f = (VEntry3 *)(self->vtbl + 0x1B8);
        s16 d = f->delta;
        void (*fn)(void *, s32, s32, ...) = f->fn;
        fn((char *)self + d, s0, r2);
    }
    func_00526860(D_005ED330);
    return 1;
}
