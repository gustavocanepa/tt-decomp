/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj {
    char pad[0x18];
    s32 a18;
    char pad1c[8];
    s32 a24;
    s32 a28;
};

extern "C" s32 func_003CA080(Obj *o) {
    if (o->a18 != 0 && o->a24 == 1 && o->a28 != o->a24) return 1;
    return 0;
}
