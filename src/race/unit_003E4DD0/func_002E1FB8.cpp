/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct V3 { f32 a, b, c; };
struct P2 { f32 a, b; };

struct Self {
    char pad0[0x1C];
    P2 *tbl44;
};

extern "C" s32 func_002E1FB8(Self *self, s32 i0, s32 i1, f32 *a3, f32 *t0, f32 *t1, f32 *t2, V3 *t3) {
    s32 v1 = (i0 + 1) & 3;
    s32 a2 = (i1 + 1) & 3;
    s32 cnt = 2;
    f32 f;
    *a3++ = t2[0];
    *a3++ = t2[1];
    *a3++ = t2[2];
    *t0++ = t2[3];
    *t0++ = t2[4];
    *a3++ = t1[0];
    *a3++ = t1[1];
    *a3++ = t1[2];
    *t0++ = t1[3];
    f = t1[4];
    for (;;) {
        *t0++ = f;
        if (v1 == a2) break;
        {
            s32 k = v1;
            v1 = (v1 + 1) & 3;
            cnt++;
            *a3++ = t3[k].a;
            *a3++ = t3[k].b;
            *a3++ = t3[k].c;
            *t0++ = self->tbl44[k].a;
            f = self->tbl44[k].b;
        }
    }
    return cnt;
}
