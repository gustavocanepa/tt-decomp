/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
struct Ent { float r, g, b, a, t; };
struct Tbl { char pad[0x24]; Ent T[5]; };
extern Tbl D_005845D0;
struct Obj { char pad[0x40]; float time; };
extern "C" u32 func_00392840(float r, float g, float b, float a) throw() __attribute__((const));

extern "C" u32 SparkParticle__getColor(Obj *p) {
    Tbl *base = &D_005845D0;
    Ent *e = &base->T[1];
    float time = p->time;
    float *tp;
    s32 i = 0;
    tp = &base->T[0].t;
    int off = 0;
    for (; i < 4; i++, tp += 5, off += 20) {
        if (tp[5] < time) {
            if (i == 0) {
            return (s32)(e->r * 127.5f) | ((s32)(e->g * 127.5f) << 8) | ((s32)(e->b * 127.5f) << 16) | ((s32)(e->a * 127.5f) << 24);
            } else {
                char *row = (char *)base + off;
                Ent *prev = (Ent *)(row + 0x24);
                Ent *cur = (Ent *)(row + 0x38);
                float f = (tp[0] - time) / (tp[0] - tp[5]);
                float g = 1.0f - f;
                return func_00392840(prev->r * g + cur->r * f, prev->g * g + cur->g * f,
                                     prev->b * g + cur->b * f, prev->a * g + cur->a * f);
            }

        }
    }
    return 0;
}
