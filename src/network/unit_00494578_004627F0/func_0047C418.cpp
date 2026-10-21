/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Obj { char p0[4]; s32 f4; s32 f8; u32 fC; u32 f10; };
extern "C" void func_0047C418(Obj *o, u32 key) {
    u32 *base = (u32 *)(o->f4 + o->f8);
    u32 i = o->f10;
    u32 start = i;
    do {
        u32 *e = (u32 *)(((-1 - i) << 2) + (u32)base);
        u32 w = *e;
        if ((w >> 2) == key) {
            *e = w & ~2u;
            o->f10 = i;
            return;
        }
        i++;
        if (!(i < o->fC)) i = 0;
    } while (i != start);
}
