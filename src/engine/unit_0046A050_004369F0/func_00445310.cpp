/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x, y; };
extern "C" void func_00444B70(float *out, const float *a, const float *b, float t);

extern "C" void func_00445310(Vec2 *out, const Vec2 *a, const Vec2 *b, float t)
{
    func_00444B70(&out->x, &a->x, &b->x, t);
    func_00444B70(&out->y, &a->y, &b->y, t);
}
