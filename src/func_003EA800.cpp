/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Circle { float x, y, pad[2], radius; };
struct Line { float x, y, pad[2], dx, dy; };
static inline float sqrt_s(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}
static inline float norm2(float x, float y) { return x*x + y*y; }
extern "C" int func_003EA800(const Circle *circle, const Line *line, float *t0, float *t1) {
    float dx = line->dx;
    float dx2 = dx*dx;
    float dy = line->dy;
    float a = dx2 + dy*dy;
    if (a == 0.0f) return -1;
    float x = circle->x, y = circle->y;
    float px = line->x, py = line->y;
    float r = circle->radius;
    float r2 = r*r;
    float b = x*dx + y*dy - dx*px - dy*py;
    float c = x*x + y*y + px*px + py*py - r2 - 2.0f*(x*px + y*py);
    float d = b*b;
    d -= a*c;
    if (d < 0.0f) return 0;
    float inv = 1.0f / a;
    if (d == 0.0f) { *t0 = b * inv; return 1; }
    d = sqrt_s(d);
    *t0 = (b - d) * inv;
    *t1 = (b + d) * inv;
    return 2;
}
