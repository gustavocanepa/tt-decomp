/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Filter mask setter: stores the mask in the target under the D_005A0B88 section and, with
   'notify', sends a kind-2 request through func_004C7D20; with no target it goes to func_004C7380.
   The kind comes in as a parameter of the inline set_(): a literal 2 swaps $v0/$v1. */
typedef unsigned long u64;

struct Target {
    int pad0[4];
    int mask;
};

struct Req {
    int m0;
    int pad4[3];
    int kind;
    int pad14[2];
    struct Target *target;
    int pad20[4];
    unsigned int flags;
    int pad34[3];
};

struct Section { int depth; int previouslyEnabled; };

extern struct Section D_005A0B88;
extern char D_0059D4A8[];
extern u64 D_006137B0;
extern void func_004A4930(struct Section *s);
extern void func_004A4970(struct Section *s);
extern void func_004C7380(void *o, int index, int value, int notify);
extern void func_004C7A48(struct Req *r, u64 key);
extern void func_004C7D20(struct Req *r, int a, int b);

static inline void set_(int kind, int mask, int notify, struct Target *target) {
    struct Req r;
    if (target != 0) {
        func_004A4930(&D_005A0B88);
        target->mask = mask;
        if (notify) {
            func_004C7A48(&r, D_006137B0);
            r.target = target;
            r.kind = kind;
            r.flags |= 9;
            func_004C7D20(&r, 0, mask);
        }
        func_004A4970(&D_005A0B88);
    } else {
        func_004C7380(D_0059D4A8, kind, mask, notify);
    }
}

void func_004C6DF0(int mask, int notify, struct Target *target) {
    set_(2, mask, notify, target);
}
