typedef int s32;

struct Obj { char pad[0xC0]; s32 fC0; char padC4[0x24]; s32 fE8; s32 fEC; };
struct Obj *func_00569110(void *);

struct Obj *func_0056B600(void *key, s32 a, s32 b) {
    struct Obj *o = func_00569110(key);
    if (o) {
        o->fEC = b;
        o->fE8 = a;
        o->fC0 = 0;
    }
    return o;
}
