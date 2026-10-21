extern "C" {
typedef float f32;
typedef int s32;

struct RaceDisplay {
    char pad0[0x58];
    s32 flags58;
};

void AutomaticFader__fadein(char *o, f32 t);
void AutomaticFader__oneshot(char *self, f32 a0, f32 a1, f32 a2, f32 a3);

void func_00356058(struct RaceDisplay *self, f32 fparg0) {
    if ((self->flags58 >> 10) & 1) {
        return AutomaticFader__oneshot((char *)self + 0x137C, 0.0f, fparg0, 0x1.333332p-3f, 0x1.333332p-3f);
    }
    AutomaticFader__fadein((char *)self + 0x137C, 0x1.333332p-3f);
}

}
