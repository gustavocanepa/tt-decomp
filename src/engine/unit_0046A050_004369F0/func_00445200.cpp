struct A { float a, b; float c[2]; float d[2]; };
extern "C" void func_00444C40(void *, void *, void *, float);
extern "C" void func_00445200(A *r, A *p, A *q, float t) {
    float u = 1.0f;
    float s = u - t;
    float pi = 0x1.921fb4p+1f;
    float x = p->a;
    float y = q->a;
    float d = x - y;
    if (d > pi) y += 0x1.921fb4p+2f;
    if (d < -pi) x += 0x1.921fb4p+2f;
    u = t * y;
    r->a = s * x + u;
    r->b = s * p->b + t * q->b;
    func_00444C40(&r->c, &p->c, &q->c, t);
    func_00444C40(&r->d, &p->d, &q->d, t);
}
