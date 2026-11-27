/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Like func_003FD980 (same unit): looks up the course segments at the source's position and
 * records the first one; returns 1 when the position lies in the first 5% of that segment. */
struct Inner {
    char pad0[0xB0];
    int mB0;
};

struct Course {
    int m0;
    Inner *inner;
};

struct Obj {
    char pad0[0x80];
    Course *course;
};

struct Src {
    char pad0[0x34];
    float pos;
    int pad38;
    int id;
};

struct Seg {
    int m0;
    float start;
    float end;
};

struct Out {
    int id;
    int mB0;
    Seg *seg;
    float pos;
};

extern "C" int func_0034BD38(Course *c, Seg **segs, int max, int id, float pos);

extern "C" int func_003A8E88(Obj *o, Src *s, Out *out) {
    Seg *segs[32];
    int id = s->id;
    float pos = s->pos;
    out->mB0 = o->course->inner->mB0;
    out->seg = 0;
    out->pos = 0;
    out->id = id;
    int n = func_0034BD38(o->course, segs, 32, id, pos);
    for (int i = 0; i < n; i++) {
        Seg *seg = segs[i];
        out->seg = seg;
        out->pos = pos;
        if ((pos - seg->start) / (seg->end - seg->start) < 0.05f) return 1;
        return 0;
    }
    return 0;
}
