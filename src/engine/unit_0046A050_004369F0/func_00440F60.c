struct Rec { char d[0x18]; };
struct T { char pad[0x50]; struct Rec *tbl; };
struct B { char pad[0x6e20]; struct T *t; };
struct A { char pad[0x14]; short idx; };
extern void func_004404F8(struct Rec *, struct B *, struct T *);
void func_00440F60(struct A *a, struct B *b) {
    struct T *t = b->t;
    struct Rec *r = t->tbl + a->idx;
    func_004404F8(r, b, t);
}
