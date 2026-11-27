/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { int size,base,offset; u32 count,index; };
extern "C" int func_0047C348(Obj *o, u32 key, int *out) {
    u32 *base = (u32 *)(o->base + o->offset);
    u32 i = o->index;
    u32 start = i;
    do {
        u32 *e = (u32 *)(((-1 - i) << 2) + (u32)base);
        u32 w = *e;
        if ((w >> 2) == key) {
            *e = w | 3;
            o->index = i;
            *out = 1;
            return o->base + o->size * i;
        }
        i++;
        if (!(i < o->count)) i = 0;
    } while(i != start);
    *out = 0;
    u32 *p = base - i - 1;
    for (;;) {
        u32 w = *p;
        if ((w & 3) == 0) {
            *p = (key << 2) | 3;
            o->index = i;
            return o->base + o->size * i;
        }
        *p = w & ~1u;
        i++;
        p--;
        if (!(i < o->count)) {
            p = base - 1;
            i = 0;
        }
    }
}
