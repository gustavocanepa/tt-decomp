/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V {
    float x, y;
    V(float a, float b) { float *px = &x; *px = a; y = b; }
    V(const V &o) { float *px = &x; *px = o.x; y = o.y; }
};
static inline V sub(float x, float y, float ox, float oy) {
    V r(x,y);
    float *px = &r.x, *py = &r.y;
    *px -= ox;
    *py -= oy;
    return r;
}
static inline float sq(V v) { return v.x*v.x + v.y*v.y; }
struct Self { char pad0[0x24]; V p; char pad2c[8]; V q, origin; char pad44[8]; float w1, u50, w2; };
extern "C" void func_003D0540(Self *self, float *a, float *b) {
    float d1 = sq(sub(self->p.x,self->p.y,self->origin.x,self->origin.y));
    float d2 = sq(sub(self->q.x,self->q.y,self->origin.x,self->origin.y));
    *a = (self->w1*d1 + self->w2*d2)/(d1+d2);
    *b = 0.5f;
}
