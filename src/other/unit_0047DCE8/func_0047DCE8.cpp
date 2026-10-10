typedef int s32;

struct P2 { s32 a, b; };
struct Q { s32 a, b, c, d; };
extern "C" void func_0047DD30(void *, s32, s32, Q *, s32);

extern "C" void *func_0047DCE8(void *self, s32 x, s32 y, P2 *p, s32 z) {
    Q q;
    q.c = p->a;
    q.d = p->b;
    q.a = 0;
    q.b = 0;
    func_0047DD30(self, x, y, &q, z);
    return self;
}
