typedef float f32;

struct Ortho {
    f32 ax, ay, az, p0;
    f32 bx, by, bz, p1;
    f32 cx, cy, cz;
};

static inline f32 rsqrt_s(f32 one, f32 s) {
    f32 r;
    __asm__("rsqrt.s %0, %1, %2" : "=f"(r) : "f"(one), "f"(s));
    return r;
}

extern "C" f32 func_002C5C58(Ortho *o) {
    f32 one = 1.0f;
    f32 ax = o->ax, ay = o->ay, az = o->az;
    f32 bx = o->bx, by = o->by, bz = o->bz;
    f32 cx = o->cx, cy = o->cy, cz = o->cz;

    f32 la = ax * ax + ay * ay + az * az;
    f32 ia = rsqrt_s(one, la);
    ax = ax * ia;
    ay = ay * ia;
    az = az * ia;
    o->ax = ax;
    o->ay = ay;
    o->az = az;

    f32 d = ax * bx + ay * by + az * bz;
    bx = bx - d * ax;
    by = by - d * ay;
    bz = bz - d * az;
    o->bx = bx;
    o->by = by;
    o->bz = bz;

    f32 lb = bx * bx + by * by + bz * bz;
    f32 ib = rsqrt_s(one, lb);
    bx = bx * ib;
    by = by * ib;
    bz = bz * ib;
    o->bx = bx;
    o->by = by;
    o->bz = bz;

    f32 e = ax * cx + ay * cy + az * cz;
    f32 f = bx * cx + by * cy + bz * cz;
    cx = cx - (e * ax + f * bx);
    cy = cy - (e * ay + f * by);
    cz = cz - (e * az + f * bz);
    o->cx = cx;
    o->cy = cy;
    o->cz = cz;

    f32 lc = cx * cx + cy * cy + cz * cz;
    f32 ic = rsqrt_s(one, lc);
    cx = cx * ic;
    cy = cy * ic;
    cz = cz * ic;
    o->cx = cx;
    o->cy = cy;
    o->cz = cz;

    return lc;
}
