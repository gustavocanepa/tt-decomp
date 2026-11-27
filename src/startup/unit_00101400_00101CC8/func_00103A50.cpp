/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct V2 { float x, y; };
struct Self { char pad0[0x44]; V2 pos; };
struct Args { char pad0[0xAC]; s32 mode; };

extern "C" void func_00103888(Self *self);

extern "C" void func_00103A50(Self *self, Args *args) {
    func_00103888(self);
    V2 *p = &self->pos;
    p->x = 0.0f;
    p->y = 1.0f;
    if (args->mode == 2) {
        p->x = -0.25f;
    }
}
