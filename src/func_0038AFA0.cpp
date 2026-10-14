/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Rec {
    f32 xyz[3];
    char pad[0x34];
    f32 w[4];
};

struct Self {
    Rec arr[7];
    char pad230[0x8];
    s32 flag;
    char *obj;
};

extern "C" void func_0038A4C8(f32 *, f32 *, f32) throw();
extern "C" void func_0038B078(Self *self);
extern "C" void func_0041C2A0(f32, f32, f32);
extern "C" void func_0041C2D8(f32, f32, f32, f32);
extern "C" void func_0041C2F8(f32);

extern "C" void func_0038AFA0(Self *self, s32 idx) {
    f32 tmp[4];
    if (self->flag != 0) {
        char *o = self->obj;
        f32 neg = -*(f32 *)(o + 0xA78);
        func_0038A4C8(tmp, self->arr[idx].w, 1.0f / *(f32 *)(o + 0x38));
        func_0041C2A0(self->arr[idx].xyz[0] * neg, self->arr[idx].xyz[1] * neg, self->arr[idx].xyz[2] * neg);
        func_0041C2D8(tmp[0], tmp[1], tmp[2], tmp[3]);
        func_0041C2F8(1.0f);
    } else {
        func_0038B078(self);
    }
}
