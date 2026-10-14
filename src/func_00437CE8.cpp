struct E { char pad[0x14]; float f; };
struct S { char pad[4]; int n; };
extern "C" struct E *func_00436968(struct S *s, int i);

extern "C" int func_00437CE8(struct S *s, int start, int *outA, int *outB, float t) {
    int n = s->n;
    int last;
    int cur, k, idx, prev;
    if (t < func_00436968(s, 0)->f) {
        *outB = n - 1;
        *outA = 0;
        return 1;
    }
    last = n - 1;
    if (func_00436968(s, last)->f <= t) {
        *outB = last;
        *outA = 0;
        return 2;
    }
    cur = start;
    for (k = 0; k <= n; k++) {
        idx = cur - k;
        if (k & 1) idx = cur + k;
        cur = idx;
        if (idx < 0) idx += n;
        else if (idx >= n) idx -= n;
        if (idx == 0) continue;
        prev = idx - 1;
        if (prev < 0) prev += n;
        if (func_00436968(s, prev)->f <= t && t < func_00436968(s, idx)->f) {
            *outB = prev;
            *outA = idx;
            return 3;
        }
    }
    return 0;
}
