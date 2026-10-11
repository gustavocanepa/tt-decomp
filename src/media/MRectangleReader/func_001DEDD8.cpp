struct Vec2 {
    float x, y;
};

struct Rect {
    float x, y, w, h;
};

extern "C" void func_00453AF8(Vec2 *p, const void *m);

extern "C" void func_001DEDD8(Rect *out, const void *m, const Rect *r) {
    Vec2 p0;
    Vec2 p1;
    Vec2 *q = &p1;
    p0.x = r->x;
    p0.y = r->y;
    q->x = r->x + r->w;
    q->y = r->y + r->h;
    func_00453AF8(&p0, m);
    func_00453AF8(q, m);
    out->x = p0.x;
    out->y = p0.y;
    out->w = q->x - p0.x;
    out->h = q->y - p0.y;
}
