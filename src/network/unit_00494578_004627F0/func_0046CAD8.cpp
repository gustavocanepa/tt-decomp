/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));

struct Node {
    Node *next;
    char pad4[5];
    signed char idx;
    char padA[6];
    u128 v10;
    u128 v20;
    u128 v30;
    u128 v40;
    u128 v50;
};

struct State {
    char pad0[0x48];
    unsigned short flags;
    char pad4A[0x310 - 0x4A];
    u128 out;
    u128 a[8];
    u128 b[8];
    char pad420[0xA60 - 0x420];
    u128 vA60;
    u128 vA70;
    union { u128 vA80; int w[3]; } A80;
    u128 vA90;
    char padAA0[0xAE0 - 0xAA0];
    u128 vAE0;
    char padAF0[0xB18 - 0xAF0];
    Node *list;
};

extern "C" void func_0046CAD8(State *s) {
    Node *n;
    s->flags &= ~4;
    if (s->A80.w[0] | s->A80.w[1] | s->A80.w[2])
        s->flags |= 8;
    else
        s->flags &= ~8;
    __asm__ volatile("vnop");
    __asm__ volatile("lqc2 $vf1, %0" : : "m"(s->vAE0));
    __asm__ volatile("lqc2 $vf2, %0" : : "m"(s->vA90));
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(s->vA60));
    __asm__ volatile("lqc2 $vf4, %0" : : "m"(s->vA70));
    __asm__ volatile("lqc2 $vf5, %0" : : "m"(s->A80.vA80));
    __asm__ volatile("vmulaw.xyzw ACC, $vf2, $vf0w");
    __asm__ volatile("vmadda.xyzw ACC, $vf1, $vf3");
    for (n = s->list; n != 0; n = n->next) {
        __asm__ volatile("lqc2 $vf6, %0" : : "m"(n->v20));
        __asm__ volatile("lqc2 $vf7, %0" : : "m"(n->v40));
        __asm__ volatile("lqc2 $vf8, %0" : : "m"(n->v10));
        __asm__ volatile("vmul.xyzw $vf6, $vf6, $vf4");
        __asm__ volatile("vmul.xyzw $vf7, $vf7, $vf5");
        __asm__ volatile("vmadda.xyzw ACC, $vf8, $vf3");
        int i = n->idx;
        if (i >= 0) {
            State *e = (State *)(i * 16 + (int)s);
            __asm__ volatile("sqc2 $vf6, %0" : "=m"(e->a[0]));
            __asm__ volatile("sqc2 $vf7, %0" : "=m"(e->b[0]));
        }
        __asm__ volatile("sqc2 $vf6, %0" : "=m"(n->v30));
        __asm__ volatile("sqc2 $vf7, %0" : "=m"(n->v50));
    }
    __asm__ volatile("vmaddx.xyzw $vf1, $vf0, $vf0x");
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(s->out));
}
