typedef float f32;
typedef unsigned char u8;

struct Obj { char pad[0x14]; u8 f14; };
extern char D_00582E98[];
extern "C" f32 func_002F4FB8(const char *);
extern "C" void func_002E4800(Obj *, f32);

extern "C" void func_002E4A90(Obj *o) {
    if (!o->f14)
        return func_002E4800(o, func_002F4FB8(D_00582E98));
}
