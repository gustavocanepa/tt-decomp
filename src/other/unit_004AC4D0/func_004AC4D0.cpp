typedef int s32;

struct Range { s32 m0; s32 lo; s32 hi; };
extern "C" s32 func_004AC488(Range *);

extern "C" void func_004AC4D0(Range *r, s32 lo, s32 hi) {
    if (hi >= lo) {
        r->lo = lo;
        r->hi = hi;
        func_004AC488(r);
        return;
    }
    r->lo = lo;
    r->hi = lo;
    func_004AC488(r);
}
