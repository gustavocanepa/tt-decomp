/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int U128 __attribute__((mode(TI)));
union V { U128 q; struct {float x,y,z,w;} f; };
struct Obj { U128 a, b; };
extern "C" void func_003D9020(Obj *out, const U128 *v) {
    V temp;
    temp.f.z = temp.f.y = temp.f.x = 0.0f;
    temp.f.w = 1.0f;
    out->a = *v;
    out->b = temp.q;
}
