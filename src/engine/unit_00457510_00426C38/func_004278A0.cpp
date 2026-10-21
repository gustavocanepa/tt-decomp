/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,o) (*(float *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define S(p,o) (*(short *)((p)+(o)))
#define U(p,o) (*(unsigned short *)((p)+(o)))
#define P(p,o) (*(char **)((p)+(o)))
static inline float fsqrt(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" void func_004278A0(char *p, char *q) {
    float ay;
    int index = S(p,0xc);
    char *next = p + 0x10;
    float ex, ey, py, px;
    if (index < 0) next += index * 0x10;
    char *base = q + 12;
    char *line = base;
    px = F(p,0);
    py = -F(p,8);
    ex = F(next,0);
    ey = -F(next,8);
    float dx = ex - px;
    int special = U(p,0xe) & 2;
    float dy = ey - py;
    float zero = 0.0f;
    float one = 1.0f;
    int i;
    int hit = 1;
    for (i = 0; i < 8; i++, line += 0x44) {
        if (I(line,0x20)) continue;
        float x2 = F(line,0x18);
        float y2 = F(line,0x1c);
        float cross2 = dx * (y2-py) - dy * (x2-px);
        if (cross2 >= 0.0f) continue;
        float x1 = F(line,0x10);
        float y1 = F(line,0x14);
        float rx = x1-px;
        float ry = y1-py;
        float cross1 = dx * ry - dy * rx;
        if (cross1 <= 0.0f) continue;
        float lx = x2-x1;
        float ly = y2-y1;
        if (lx*ry - ly*rx < 0.0f) continue;
        float tox = x1-ex;
        float toy = y1-ey;
        if (lx*toy - ly*tox > 0.0f) continue;
        float denominator = cross1-cross2;
        float t = 1.0f;
        if (denominator != 0.0f) t = cross1 / denominator;
        if (!(t < F(line,0x28))) continue;
        if (special) {
            if (t < F(q,0x408)) { F(q,0x408) = t; I(q,0x404) = hit; }
        } else {
            F(line,0x28) = t;
            I(line,0x24) = hit;
            P(line,0x2c) = p;
            float len = fsqrt(dx*dx + dy*dy);
            if (len == zero) {
                F(line,0x30) = one;
                I(line,0x34) = 0;
            } else {
                F(line,0x30) = dx / len;
                F(line,0x34) = dy / len;
            }
        }
    }
    int flags = U(p,0xe);
    if ((flags ^ 1) & 1) return;
    char *cur = base;
    char *prev = q + 0x1E8;
    for (i = 0; i < 8; i++, prev = cur, cur += 0x44) {
        float bx2 = F(prev,0x18);
        float by2 = F(prev,0x1c);
        float ax2 = F(cur,0x18);
        float ay2 = F(cur,0x1c);
        float cross2 = (ax2-bx2)*(py-by2) - (ay2-by2)*(px-bx2);
        if (cross2 <= 0.0f) continue;
        float bx1 = F(prev,0x10);
        float by1 = F(prev,0x14);
        float ax1 = F(cur,0x10);
        float ay1 = F(cur,0x14);
        float cx = px-bx1;
        float cy = py-by1;
        float rx = ax1-bx1;
        float ry = ay1-by1;
        float cross1 = rx*cy - ry*cx;
        if (cross1 >= 0.0f) continue;
        float bx = bx2-bx1;
        float by = by2-by1;
        ay2 -= ay1;
        ay = ay2;
        float ax = ax2-ax1;
        float side1 = bx*ry - by*rx;
        float side2 = bx*cy - by*cx;
        float ptx = px-ax1;
        float pty = py-ay1;
        float side3 = ax*pty - ay*ptx;
        if (side1 < 0.0f) {
            if (side2 > 0.0f) continue;
            if (side3 > 0.0f) continue;
        }
        if (ax*ry - ay*rx < 0.0f) {
            if (side2 < 0.0f) continue;
            if (side3 < 0.0f) continue;
        }
        if (side2 < 0.0f) continue;
        if (side3 > 0.0f) continue;
        float denominator = cross1-cross2;
        float t = 1.0f;
        if (denominator != 0.0f) t = cross1 / denominator;
        if (special) {
            if (t < F(q,0x408)) { F(q,0x408) = t; I(q,0x404) = 1; }
        } else {
            char *dst = q + 0x22C + ((i+7)&7) * 0x2c;
            if (t < F(dst,0x24)) {
                F(dst,0x24) = t;
                I(dst,0x20) = 1;
                P(dst,0x28) = p;
            }
        }
    }
}
