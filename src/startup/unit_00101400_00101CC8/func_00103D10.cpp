/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct V2 { float x, y; };
struct Self {
    char pad0[0x60];
    V2 pos;
    s32 f54;
    s32 f58;
};
struct Args { char pad0[0xAC]; s32 mode; };

extern s32 D_00579308;

extern "C" void func_00103888(Self *self) throw();
extern "C" s32 func_004B2AC8();

extern "C" void func_00103D10(Self *self, Args *args) {
    func_00103888(self);
    if (self->f58 == 0) {
        self->f58 = D_00579308;
    }
    s32 m = args->mode;
    switch (m) {
    case 0: {
        self->f54 = func_004B2AC8() & 1;
        V2 *p = &self->pos;
        p->y = p->x = 0.0f;
        break;
    }
    case 2:
        self->pos.x = -0.25f;
        break;
    }
}
