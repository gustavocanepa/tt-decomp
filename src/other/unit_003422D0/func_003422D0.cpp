typedef float f32;

struct Obj;

extern "C" char *func_00341AD8(Obj *arg0);

extern "C" f32 func_003422D0(Obj *arg0) {
    return *(f32 *)(func_00341AD8(arg0) + 0x74);
}
