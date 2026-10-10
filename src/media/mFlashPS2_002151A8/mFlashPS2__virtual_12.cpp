typedef int s32;
typedef float f32;

struct Obj { char pad[0x10]; void *f10; s32 f14; char pad18[4]; s32 f1C; };
extern "C" void func_0043C0D8(void *, f32);

extern "C" void mFlashPS2__virtual_12(Obj *o) {
    if (o->f1C && o->f10 && o->f14)
        func_0043C0D8(o->f10, 1.0f / 60.0f);
}
