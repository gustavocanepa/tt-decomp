typedef int s32;

struct Id { char b[8]; };
extern struct Id D_005981E0;

struct Obj {
    struct Id id;
    struct Id a;
    struct Id b;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
};

void func_004A8BB8(struct Obj *o, s32 x, const struct Id *id) {
    o->id = *id;
    o->a = D_005981E0;
    o->b = D_005981E0;
    o->f18 = x;
    o->f1C = 0;
    o->f20 = 0;
    o->f24 = 1;
}
