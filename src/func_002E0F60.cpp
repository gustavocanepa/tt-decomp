/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Obj {
    char *items;
    s32 count;
};
extern char D_005F2C28[];
extern "C" void func_00424178(void *, void *, void *);
extern "C" void func_00423BB0(void *, s32);
extern "C" void func_00423BF0(void *, s32);
extern "C" void func_00423C10(void *, s32);
extern "C" void func_004241E8(void *, void *);
extern "C" s32 func_002E0AB8(Obj *, void *) throw();
extern "C" s32 func_002DED20(void *) throw();
extern "C" void func_002E1150(void *, void *);

extern "C" void func_002E0F60(Obj *self, void *w) {
    s32 buf[4];
    s32 i = 0;
    func_00424178(buf, w, D_005F2C28);
    func_00423BB0(w, 0);
    func_00423C10(w, self->count);
    if (self->count > 0) {
        s32 off = 0;
        do {
            char *it = self->items + off;
            off += 0x60;
            s32 ok = func_002E0AB8(self, it);
            func_00423BF0(w, ok);
            if (ok) {
                s32 f = func_002DED20(it) ^ 1;
                func_00423BF0(w, f);
                if (f) func_002E1150(it, w);
            }
            i++;
        } while (i < self->count);
    }
    func_004241E8(buf, w);
}
