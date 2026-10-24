/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Vec2 {
    f32 x, y;
};
struct Obj {
    int pad[5];
    int ready;
};
extern "C" void func_00439B48(Obj *, int, Vec2 *, int, int) throw();
extern "C" void func_0043A180(Obj *);
extern "C" Vec2 *func_00473980(int);

static inline f32 sqrtf_(f32 x)
{
    f32 r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_00439BB8(Obj *o, Vec2 *src, int count, int closed, f32 width)
{
    if (count < 2)
        return;
    if (o->ready == 0)
        func_0043A180(o);
    Vec2 *base = func_00473980((count * 16 + 31) >> 4);
    Vec2 *in = src;
    f32 x0 = in[0].x, y0 = in[0].y;
    f32 x = in[1].x, y = in[1].y;
    in += 2;
    f32 ny = x0 - x;
    f32 nx = y - y0;
    f32 half = width * 0.5f;
    f32 inv = 1.0f / sqrtf_(nx * nx + ny * ny);
    nx *= inv;
    ny *= inv;
    f32 fnx = nx, fny = ny;
    if (!closed) {
        f32 ox = nx * half, oy = ny * half;
        base[0].x = x0 + ox;
        base[0].y = y0 + oy;
        base[1].x = x0 - ox;
        base[1].y = y0 - oy;
    }
    f32 py = 0.0f, px = 0.0f, nnx = 0.0f, nny = 0.0f;
    Vec2 *out = base + 2;
    for (int i = 1; i < count; i++) {
        f32 ox, oy;
        if (i == count - 1 && !closed) {
            ox = nx * half;
            oy = ny * half;
        } else {
            if (i == count - 1) {
                nnx = fnx;
                nny = fny;
            } else {
                px = in->x;
                py = in->y;
                in++;
                nny = x - px;
                nnx = py - y;
                f32 r = 1.0f / sqrtf_(nnx * nnx + nny * nny);
                nnx *= r;
                nny *= r;
            }
            f32 dot = nx * nnx + ny * nny;
            if (dot < -0.5f) {
                half = -half;
                f32 s = half / (1.0f - dot);
                ox = (nnx - nx) * s;
                oy = (nny - ny) * s;
            } else {
                f32 s = half / (dot + 1.0f);
                ox = (nnx + nx) * s;
                oy = (nny + ny) * s;
            }
        }
        out[0].x = x + ox;
        out[0].y = y + oy;
        out[1].x = x - ox;
        out[1].y = y - oy;
        nx = nnx;
        ny = nny;
        x = px;
        y = py;
        out += 2;
    }
    if (closed) {
        Vec2 *a, *b;
        if (half < 0.0f) {
            a = out - 1;
            b = out - 2;
        } else {
            a = out - 2;
            b = out - 1;
        }
        base[0].x = a->x;
        base[0].y = a->y;
        base[1].x = b->x;
        base[1].y = b->y;
    }
    func_00439B48(o, out - base, base, 0, 0);
}
