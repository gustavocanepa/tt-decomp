#include "types.h"
struct Rect {
    float x, y, w, h;
    Rect() {}
    Rect(float a, float b, float c, float d) : x(a), y(b), w(c), h(d) {}
    Rect(const Rect &r) : x(r.x), y(r.y), w(r.w), h(r.h) {}
    Rect &operator=(const Rect &o) {
        if (this != &o) { x = o.x; y = o.y; w = o.w; h = o.h; }
        return *this;
    }
};
struct Clips { char pad[12]; Rect rects[100]; };
struct Obj { char pad[0x80]; Clips clips; };
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VEntry1 { s16 delta; s16 index; void (*fn)(void *); };
extern "C" s32 func_001E4EC0(void *) throw();

static inline float minf(float a, float b) { return b < a ? b : a; }
static inline float maxf(float a, float b) { return a < b ? b : a; }
static inline Rect intersect(const Rect &a, const Rect &b) {
    float x = maxf(b.x, a.x);
    float ay = a.y, by = b.y; float y = by < ay ? ay : by;
    float ar = a.x + a.w, br = b.x + b.w; float w = (br < ar ? br : ar) - x;
    float ab = ay + a.h, bb = by + b.h; float h = (bb < ab ? bb : ab) - y;
    if (w <= 0 || h <= 0) w = h = 0;
    return Rect(x, y, w, h);
}
static inline bool nonempty(const Rect &r) { return 0 < r.w && 0 < r.h; }

extern "C" void func_001E4F30(char *self, Rect *arg1) {
    if (func_001E4EC0(self) != 0) {
        s32 n = *(s32 *)(self + 0x6CC) + 1;
        *(s32 *)(self + 0x6CC) = n;
        if (n > 0) {
            Rect *prev = (Rect *)(self + n * 16 + 0x7C);
            *(Rect *)(self + n * 16 + 0x8C) = intersect(*prev, *arg1);
        } else {
            Rect *slot = (Rect *)(self + n * 16 + 0x8C);
            *slot = *arg1;
            VEntry1 *e = (VEntry1 *)(*(char **)(self + 4) + 0x200);
            e->fn(self + e->delta);
        }
        s32 m = *(s32 *)(self + 0x6CC);
        if (0 < ((Obj *)self)->clips.rects[m].w && 0 < ((Obj *)self)->clips.rects[m].h) {
            VEntry *e = (VEntry *)(*(char **)(self + 4) + 0x210);
            e->fn(self + e->delta, self + m * 16 + 0x8C);
        }
    }
}
