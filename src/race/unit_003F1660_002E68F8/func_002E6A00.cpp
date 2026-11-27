/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x6B4]; short timer; };
extern "C" int func_002E6A00(Obj *o) {
    int n = o->timer;
    unsigned int u = (unsigned short)o->timer;
    if (n <= 0) return 0;
    int t = u - 1;
    o->timer = t;
    return (t << 16) == 0;
}
