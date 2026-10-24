/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long long s64;
struct Obj { char pad[12]; int count; s64 ids[1]; };
extern "C" int func_003F7BC0(Obj *o, s64 key) {
    int i = 0;
    int n = o->count;
    s64 *p;
    if (n > 0) {
        p = o->ids;
        while (p[i] != key) {
            i++;
            if (i >= o->count) goto fail;
        }
        if (i < n) goto found;
    }
fail:
    return -1;
found:
    int j = i;
    if (j < o->count - 1) {
        s64 *q = (s64 *)(j * 8 + (int)p);
        do { *q = q[1]; j++; q++; } while (j < o->count - 1);
    }
    *(s64 *)(o->count * 8 + (int)p - 8) = -1;
    o->count--;
    return i;
}
