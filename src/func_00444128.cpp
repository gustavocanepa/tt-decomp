/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { int w[9]; };
struct Arr { Rec *data; int count; Rec &operator[](int i) { Rec *p = data+i; return *p; } };
struct Inner { char pad[2]; short h; char pad2[0x14]; Arr list; };
struct Obj {
    char pad[4];
    Inner *p;
    Rec dst;
    Rec cur;
};
static inline const int &mn(const int &a, const int &b) { return b < a ? b : a; }
extern "C" void func_00444128(Obj *o, int unused, int a2) {
    Rec *cur = &o->cur;
    o->dst = *cur;
    if (o->p) {
        Arr *l = &o->p->list;
        a2 = a2 - o->p->h;
        a2 = a2 < 0 ? 0 : a2;
        if (l->count >= 2) {
            *cur = (*l)[mn(a2, l->count - 1)];
        }
    }
}
