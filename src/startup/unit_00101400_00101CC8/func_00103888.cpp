/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct F2 { f32 a; f32 b; };
struct Self { char pad[0x44]; F2 v; };
struct Other { char pad[0xAC]; s32 mode; };
extern "C" void func_001036F0(void *, void *) throw();

static inline F2 *getv(Self *s) { return &s->v; }

extern "C" void func_00103888(Self *arg0, Other *arg1) {
    func_001036F0(arg0, arg1);
    switch (arg1->mode) {
    case 0: {
        F2 *q = getv(arg0);
        *(s32 *)&q->b = 0;
        q->a = 1.0f;
        break; }
    case 1: {
        F2 *p = getv(arg0);
        *(s32 *)&p->a = 0;
        p->b = 1.0f;
        break; }
    case 2:
        arg0->v.a = -0.25f;
        break;
    }
}
