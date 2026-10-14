struct Node {
    char pad0[4];
    float x4;
    char pad8[4];
    float xC;
    char pad10[3];
    unsigned char x13;
    char pad14[8];
    int x1c;
};
struct Obj {
    char pad0[8];
    float x8;
};
static inline int cont(Node *k, int n) { return k->x13 != 0 && k->x1c < n; }
static inline int isEnd(Node *k) { return k->x13 >= 2; }
extern "C" Node *GT4_Motion__PlayList__getElement(Obj *, float);
extern "C" Node *func_003F1A50(Obj *, Node *);
extern "C" float func_003F18E8(Node *, float);

extern "C" float func_003F0FA0(Obj *o, int n, float t, float dt) {
    Node *s3;
    Node *s0 = GT4_Motion__PlayList__getElement(o, t);
    if (s0 == 0) goto fail;
    t = t + dt;
    if (s0->x1c < n) {
        s3 = s0;
        s0 = GT4_Motion__PlayList__getElement(o, t);
        if (isEnd(s0) && s0->x1c < n) {
            s0 = func_003F1A50(o, s0);
            if (s0 == 0) goto fail;
            t = s0->x4;
        }
        if (s0 == 0) goto fail;
        if (s3 != s0) {
        top:
            if (s0->x13 == 0 || s0->x1c >= n) goto done;
            s0 = func_003F1A50(o, s0);
            if (s0 == 0) goto fail;
            t = s0->x4;
            goto top;
        }
    done:
        if (s0 == 0) { fail: t = o->x8; goto out; }
        if (s3 != s0 || s0->x1c < n) goto out;
    }
    t = func_003F18E8(s0, t);
    if (s0->x4 + s0->xC <= t) t = t - dt * 0x1.0624dcp-10f;
    goto out;
out:
    return t;
}
