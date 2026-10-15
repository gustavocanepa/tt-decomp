typedef int s32;
typedef long long s64;

typedef struct {
    s32 a;
    s32 b;
} Elem;

struct Pivot {
    s64 v;
    void *p;
};

extern "C" void *func_005517E0(void *arg0, void *arg1, s64 arg2, s32 (*arg3)(void *, void *)) {
    struct Pivot pv;
    Elem tmp;
    Elem *t = &tmp;
    char *lo = (char *)arg0;
    char *hi = (char *)arg1;

    pv.v = arg2;
    for (;;) {
        while (arg3(lo, &pv) != 0) {
            lo += 8;
        }
        hi -= 8;
        while (arg3(&pv, hi) != 0) {
            hi -= 8;
        }
        if (!(lo < hi)) {
            return lo;
        }
        pv.p = lo;
        *t = *(Elem *)lo;
        *(Elem *)lo = *(Elem *)hi;
        lo += 8;
        *(Elem *)hi = *t;
    }
}
