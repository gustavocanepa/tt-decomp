/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { char pad[0xC]; int v; };
struct O { char *p; };

extern "C" int func_0041AB80(O *o, int f) {
    char *p = o->p;
    int r;
    if (p) {
        unsigned int off = 0x20;
        if (f == 0) off = 0x24;
        r = *(int *)(p + off + 0xC);
    } else {
        r = 0;
    }
    return r;
}
