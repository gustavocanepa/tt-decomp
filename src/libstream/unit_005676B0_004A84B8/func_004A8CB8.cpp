/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair {
    int a;
    int b;
};

extern "C" Pair D_005981D8;
extern "C" int func_004A8DF0(int a);

struct func_004A8CB8 {
    Pair m0;
    Pair m8;
    Pair m10;
    int m18;
    int m1C;
    int m20;
    int m24;
    func_004A8CB8(int a, int b, const Pair *p, const Pair *q);
};

func_004A8CB8::func_004A8CB8(int a, int b, const Pair *p, const Pair *q)
    : m0(D_005981D8), m8(*p), m10(*q), m18(a), m1C(b), m20(func_004A8DF0(b)), m24(1)
{
}
