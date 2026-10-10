typedef int s32;
typedef float f32;

struct Obj;

extern "C" s32 func_00341AD8(Obj *arg0);

extern "C" f32 func_00342318(Obj *arg0) {
    return *(f32 *)(func_00341AD8(arg0) + 0x8C);
}
