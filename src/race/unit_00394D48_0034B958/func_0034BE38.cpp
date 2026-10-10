struct Shape;
struct Query {
    float a[3];
    float b[3];
};

struct Obj {
    int unk0;
    Shape *shape;
};

extern "C" float func_0034BAA8(Shape *s, Query *q);
extern "C" float func_0034BBB0(Shape *s, Query *q);
extern "C" float func_0034BAD8(Shape *s, Query *q, float *b);

extern "C" float func_0034BE38(Obj *o, int kind, Query *q) {
    switch (kind) {
    case 0:
        return func_0034BAA8(o->shape, q);
    case 1:
        return func_0034BBB0(o->shape, q);
    case 2:
        return func_0034BAD8(o->shape, q, q->b);
    }
    return 0.0f;
}
