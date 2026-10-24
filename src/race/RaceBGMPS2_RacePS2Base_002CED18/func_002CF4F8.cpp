/* compiler: ee-gcc2.96-nogcse */
typedef int s32;

struct In { float m[3][3]; float f24; s32 pad28[2]; s32 i30; s32 i34; };
struct Out { s32 i0; s32 i4; float m[3][3]; s32 i2c; float f30; };

static inline float &el(float *p, int i) { return *(float *)((char *)p+i); }

extern "C" s32 func_00396BC0(void *, void *, s32);
extern "C" s32 Pitmen__isPitCameraPeriod(void *);

extern "C" s32 func_002CF4F8(char *arg0, void *arg1, Out *arg2) {
    void *s2 = arg0 + 0x36C0;
    if (Pitmen__isPitCameraPeriod(s2)) {
        arg2->i0 = func_00396BC0(s2, arg1, *(s32 *)(arg0 + 0x70));
        In *in = (In *)(arg0 + 0x36C4);
        s32 v = in->i30;
        arg2->i4 = v;
        arg2->i2c = in->i34;
        if (v != 0) {
            s32 i = 0;
            float *oa = arg2->m[0];
            float *ia = in->m[0];
            float *ob = (float *)&arg2->i4;
            float *ib = in->m[1];
            float *oc = arg2->m[2];
            float *ic = &in->m[0][2];
            for (; i < 3; i++) {
                int off=i*4;
                el(oa,off) = el(ia,off);
                el(ob,off+16) = el(ib,off);
                *oc = el(ic,off+16);
                oc++;
            }
        }
        if (arg2->i2c != 0) {
            arg2->f30 = in->f24;
        }
        return 1;
    }
    arg2->i0 = -1;
    arg2->i4 = 0;
    arg2->i2c = 0;
    return 0;
}
