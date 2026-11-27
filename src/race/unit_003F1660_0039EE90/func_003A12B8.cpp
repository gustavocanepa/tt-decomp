/* compiler: ee-gcc2.96-nogcse */
typedef unsigned char u8;
struct Ref { char p[0xC]; float fc; };
struct Inner { float pos[3]; float a[3]; float b[3]; char p[0x4D1 - 0x24]; u8 flags; };
struct Obj { char p[0x10]; Ref *ref; char q[0x104 - 0x14]; Inner s; };
struct Out { float f0, f4, f8, fc, f10; };
extern "C" int func_002E4D58(Obj *);

extern "C" int func_003A12B8(Out *out, Obj *o1, Obj *o2)
{
    Inner *s2 = &o1->s;
    Inner *s1 = &o2->s;
    float d[3];
    int i;
    if (func_002E4D58(o1) != 0)
        return 0;
    if (func_002E4D58(o2) != 0)
        return 0;
    if ((s2->flags & 0x10) != (s1->flags & 0x10))
        return 0;
    for (i = 0; i < 3; i++)
        d[i] = s1->pos[i] - s2->pos[i];
    float sum = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
    float dist;
    __asm__("sqrt.s %0, %1" : "=f"(dist) : "f"(sum));
    out->f10 = dist;
    if (dist > 100.0f)
        return 0;
    Ref *r2 = o2->ref;
    Ref *r1 = o1->ref;
    float limit1 = r1->fc;
    if (!(d[2] < -(r2->fc + 5.0f))) {
    if (limit1 + 5.0f < d[2])
        return 0;
    out->f0 = out->f4 = out->f8 = out->fc = 0.0f;
    } else {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        out->f0 = out->f0 + s2->a[i] * d[i];
        out->f4 = out->f4 + s2->b[i] * d[i];
        out->f8 = out->f8 - s1->a[i] * d[i];
        out->fc = out->fc - s1->b[i] * d[i];
    }
    return 1;
}
