struct B;
struct Obj;

extern "C" int func_0030E320(struct B *b, int row, int col);
extern "C" float func_0030E348(struct B *b, int row, int col);
extern "C" float func_002F0570(struct Obj *o);

extern "C" int func_0030E370(struct B *b, int row, int col, float *out)
{
    int n = func_0030E320(b, row, col);
    float f20 = func_0030E348(b, row, col);
    float len = func_002F0570((struct Obj *)b);
    float half = len * 0.5f;

    if (half < f20) {
        f20 = f20 - len;
        n += 1;
    } else if (f20 < -half) {
        f20 = f20 + len;
        n -= 1;
    }

    *out = f20;
    return n;
}
