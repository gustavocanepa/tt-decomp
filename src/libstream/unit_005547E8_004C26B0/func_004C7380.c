/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;

struct Entry {
    int m0;
    int m4;
    int m8;
};

struct Obj {
    char pad0[0x4C];
    struct Entry entries[1];
};

struct Req {
    int m0;
    int pad4[3];
    int index;
    int pad14[7];
    unsigned int flags;
    int pad34[3];
};

extern u64 D_006137B0;
extern void func_004C7A48(struct Req *r, u64 key);
extern void func_004C73F8(int a, struct Req *r, void (*cb)(void), int b, int c);
extern void func_004C7A08(void);

void func_004C7380(struct Obj *o, int index, int value, int notify) {
    struct Req r;
    o->entries[index].m0 = value;
    if (notify) {
        func_004C7A48(&r, D_006137B0);
        r.index = index;
        r.flags |= 1;
        func_004C73F8(r.m0, &r, func_004C7A08, 0, 0);
    }
}
