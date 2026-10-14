typedef int s32;
typedef float f32;

extern "C" f32 func_003174F8(f32 a, f32 b) throw();

struct Obj {
    s32 count;          /* 0x00 */
    f32 x;              /* 0x04, stored from $f12 */
    f32 y;              /* 0x08, passed as second float argument */
    char pad[0x78];     /* 0x0C..0x84 */
    union { s32 w; f32 f; } r84;  /* 0x84 */
};

extern "C" void func_0032E258(Obj *o, f32 f) {
    s32 c;
    f32 *p;
    s32 n;

    c = o->count;
    if (c < 0x20) {
        o->count = c + 1;
    }
    n = 0x1F;
    p = (f32 *)((char *)o + 0x80);
    do {
        n--;
        p[0] = p[-1];
        p[0x20] = p[0x1F];
        p--;
    } while (n > 0);
    o->x = f;
    o->r84.w = 0;
    if (*(volatile s32 *)&o->count >= 2) {
        o->r84.f = func_003174F8(f, o->y);
    }
}
