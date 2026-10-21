struct E { float v; char pad[12]; };
extern "C" E *func_00561648(E *base, int n, E *cur, float x) {
    if (!(cur + 1 < (E *)((float *)base + n))) cur = base;
    if (x < cur->v) {
        for (;;) {
            cur--;
            if (cur < base) return base;
            if (cur->v <= x) return cur;
        }
    }
    if (cur[1].v < x) {
        E *nx, *prev, *p;
        base = (E *)((float *)base + n);
        p = cur + 1;
        for (;;) {
            cur = p;
            nx = cur + 1;
            prev = cur - 1;
            p = nx;
            if (!(nx < base)) return prev;
            if (x <= nx->v) return cur;
        }
    }
    return cur;
}
