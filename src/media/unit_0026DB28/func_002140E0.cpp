/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rect { float x, y, z, w; };
struct Vec { char pad[4]; Rect *begin; Rect *end; Rect *cap; };

extern "C" void func_00531068(void *, void *, void *);

static inline void construct(Rect *p, const Rect *r) {
    if (p != 0) {
        p->x = r->x;
        p->y = r->y;
        p->z = r->z;
        p->w = r->w;
    }
}

extern "C" void func_002140E0(char *arg0, Rect *arg1) {
    Vec *v = (Vec *)(arg0 + 0x40);
    if (v->end - v->begin != 0) {
        Rect *last = v->end - 1;
        Rect t;
        float a = arg1->x < last->x ? last->x : arg1->x;
        float b = arg1->y < last->y ? last->y : arg1->y;
        float c = arg1->z < last->z ? arg1->z : last->z;
        float d = arg1->w < last->w ? arg1->w : last->w;
        if (c <= a || d <= b) {
            c = a;
            d = b;
        }
        t.y = b;
        t.z = c;
        t.w = d;
        t.x = a;
        if (v->end != v->cap) {
            construct(v->end, &t);
            v->end = v->end + 1;
        } else {
            func_00531068(v, v->end, &t);
        }
    } else {
        if (v->end != v->cap) {
            construct(v->end, arg1);
            v->end = v->end + 1;
        } else {
            func_00531068(v, v->end, arg1);
        }
    }
}
