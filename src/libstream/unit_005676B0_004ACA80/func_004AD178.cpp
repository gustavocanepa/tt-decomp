/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Res {
    s32 refs;
};

struct Slot {
    s32 key;
    struct Res *res;
};

struct Table {
    char pad0[0x3C];
    s32 unk3C;
    char pad40[0x0C];
    struct Slot *slots;   /* 0x4C */
    s32 pad50;
    s32 count;            /* 0x54 */
};

extern "C" void func_004A4D68(void *);
extern "C" s32 func_004AD398(struct Table *t, u32 key);
extern "C" void func_004AD498(struct Table *t, void *slot);
extern "C" void func_004AD628(struct Table *t, void *res);
extern "C" void func_004A4DD8(void *);

extern "C" void func_004AD178(struct Table *t, u32 key) {
    struct Slot *slot;
    struct Res *res;
    s32 n;
    s32 i;

    func_004A4D68(t);
    i = func_004AD398(t, key);
    if (i >= 0) {
        slot = &t->slots[i];
        res = slot->res;
        n = res->refs;
        if (n & 1) {
            n = n - 1;
            res->refs = n;
            t->count = t->count - 1;
        }
        n = n + 0xC;
        t->unk3C = t->unk3C + n;
        func_004AD498(t, slot);
        func_004AD628(t, res);
    }
    func_004A4DD8(t);
}
