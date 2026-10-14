/* compiler: ee-gcc2.96-nogcse */
struct S {
    int mode;
    int cnt;
    int f8;
    int c;
    int d;
};
struct O {
    int a;
    int b;
};
extern float D_00584F18[];
extern float D_00584F30[];
extern "C" float func_005357F8(int);

static inline bool equal(int x, int y) { return x == y; }
static inline void set(S *s, int v) { s->d = v; }
extern "C" void func_003AAC10(S *s, O *o) {
    int done = 0;
    o->a = 2;
    o->b = 0;
    switch (s->mode) {
    case 1: {
        s->cnt = s->cnt + 1;
        if (s->cnt >= 8)
            s->cnt = 0;
        int v = s->cnt;
        if (v < 0) {
            s->cnt = 0;
            v = 0;
        }
        if (v & 1) {
            o->a = 1;
            o->b = (v >> 1) + 0x15;
        }
        break;
    }
    case 2: {
        float f = func_005357F8(s->f8);
        int c = s->c;
        if (equal(c, 1)) {
            int t = s->d + 1;
            t = done < t ? t : 0;
            s->d = t;
            int v = t;
            if (v >= 3) {
                set(s, 3);
                v = 3;
            }
            if (f < D_00584F30[v]) {
                o->a = c;
                o->b = 0;
            } else {
                done = 1;
            }
        } else {
            int t = s->d + 1;
            t = done < t ? t : 0;
            s->d = t;
            int v = t;
            if (v >= 5) {
                set(s, 5);
                v = 5;
            }
            if (f < D_00584F18[v]) {
                o->a = 1;
                done = 1;
                o->b = 0;
            }
        }
        break;
    }
    }
    s->c = o->a;
    if (done) {
        s->cnt = 0;
        s->d = 0;
    }
}
