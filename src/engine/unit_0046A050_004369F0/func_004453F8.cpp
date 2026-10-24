#include "types.h"
struct Color { unsigned char r, g, b, a; int m4; };
extern "C" void func_00444A78(Color *, u32, u32, u32, u32);
extern "C" int func_00445370(Color *, int *);

extern "C" void func_004453F8(Color *d, Color *o)
{
    func_00444A78(d, (u32)o->r * d->r >> 7, (u32)o->g * d->g >> 7, (u32)o->b * d->b >> 7, (u32)o->a * d->a >> 7);
    d->m4 = func_00445370(o, &d->m4);
}
