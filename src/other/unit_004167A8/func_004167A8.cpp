typedef int s32;

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_00416738(void);
extern "C" void func_004167F0(void *self, s32 x, void (*cb)(void), Pair *p);

extern "C" void func_004167A8(void *self, s32 a, s32 b, s32 x) {
    if (a || b) {
        Pair p;
        p.a = a;
        p.b = b;
        func_004167F0(self, x, func_00416738, &p);
    }
}
