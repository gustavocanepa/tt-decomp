/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 { float x, y; };
struct Angle { float v; };
extern "C" Angle *func_003E7A00(Angle *, const V2 *, const V2 *) throw();
extern "C" Angle *func_003E7DF0(Angle *out, const V2 *a, const V2 *b, int dir) {
    Angle angle[4];
    V2 perpendicular[2];
    Angle negated[4];
    func_003E7A00(angle, a, b);
    V2 *p = perpendicular;
    p->x = -a->y;
    p->y = a->x;
    if (dir != 1) {
        negated[0].v = -angle[0].v;
        angle[0].v = negated[0].v;
    }
    if (p->x * b->x + p->y * b->y > 0.0f) out->v = angle[0].v;
    else out->v = -angle[0].v;
    return out;
}
