/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x2C]; int a; int b; };
extern "C" int func_0019AEC8(struct Obj *o, int x, int y) {
    if (o->a == x) {
        o->b = y;
    } else {
        if (o->b != x) return 0;
        o->a = y;
    }
    return 1;
}
