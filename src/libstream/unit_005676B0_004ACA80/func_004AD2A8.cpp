/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Res {
    int refs;
};

struct Slot {
    int key;
    struct Res *res;
};

struct Table {
    char pad0[0x4C];
    struct Slot *slots;
    int pad50;
    int count;
    Slot *at(int i) { return &slots[i]; }
};

extern "C" void func_004A4D68(struct Table *t);
extern "C" void func_004A4DD8(struct Table *t);
extern "C" int func_004AD398(struct Table *t, int key);

extern "C" void func_004AD2A8(struct Table *t, int key) {
    int i;
    func_004A4D68(t);
    i = func_004AD398(t, key);
    if (i >= 0) {
        struct Res *r = t->at(i)->res;
        int n = r->refs;
        if (n & 1) {
            r->refs = n - 1;
            t->count--;
        }
    }
    func_004A4DD8(t);
}
