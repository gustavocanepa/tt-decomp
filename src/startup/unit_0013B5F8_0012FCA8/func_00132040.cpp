typedef int s32;
typedef float f32;
struct Text5 { char bytes[5]; };
struct Obj { char pad[0x17C]; s32 value; };
extern void *D_00586EF8;
extern "C" const Text5 D_005E0FD8;
extern "C" f32 func_001321D0(Obj *);
extern "C" void func_0045F468(void *, void *, s32, s32);
extern "C" void func_00132040(Obj *self, s32 size, char *buffer) {
    s32 value = self->value;
    f32 scale = func_001321D0(self);
    if (value <= 0) {
        *(Text5 *)buffer = D_005E0FD8;
        return;
    }
    if (scale <= 0.0f) {
        *(Text5 *)buffer = D_005E0FD8;
        return;
    }
    s32 shown = (s32)(((f32)self->value / func_001321D0(self)) * 1000.0f + 0.5f);
    func_0045F468(D_00586EF8, buffer, size, shown);
}
