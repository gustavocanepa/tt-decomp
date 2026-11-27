/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V6 { float f[6]; };
struct St {
    void *h; V6 cur; V6 tgt; float t34; float p38; unsigned flags;
};
extern "C" void func_003AB948(St *) throw();
extern "C" float func_003ABC68(float, float, float) throw() __attribute__((const));
extern "C" float func_005357F8(void *);

extern "C" void func_003ABC78(St *s, int reset)
{
    void *h = s->h;
    func_005357F8(h);
    s->t34 = s->t34 + 0.016666666f;
    if (reset != 0) {
        s->cur = s->tgt;
        func_003AB948(s);
        s->flags = ((s->flags & 0xFFFF00FFu) | 0x100) & ~0xFFu;
        if (func_005357F8(h) < 0x1.999998p-3f) s->flags = (s->flags & ~0xFFu) | 1;
    }
    if ((unsigned char)s->flags != 0) {
        float k = func_005357F8(h) * 0.04f + 0.015f;
        float cc = s->cur.f[0];
        float tt = s->tgt.f[0];
        s->cur.f[0] = func_003ABC68(tt, cc, k);
        s->cur.f[1] = func_003ABC68(s->tgt.f[1], s->cur.f[1], k);
        s->cur.f[2] = func_003ABC68(s->tgt.f[2], s->cur.f[2], k);
        s->cur.f[5] = func_003ABC68(s->tgt.f[5], s->cur.f[5], k);
        s->cur.f[3] = func_003ABC68(s->tgt.f[3], s->cur.f[3], k);
        float cd = s->cur.f[4];
        float td = s->tgt.f[4];
        s->cur.f[4] = func_003ABC68(td, cd, k);
    } else {
        s->cur = s->tgt;
    }
}
