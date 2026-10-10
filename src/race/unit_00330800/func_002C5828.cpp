extern "C" void func_004A45D0(void *p);

struct Holder {
    int *p;
    Holder(int *q) : p(q) {}
    ~Holder() { if (p) func_004A45D0(p); }
};

struct Ctx {
    int m0;
    int *start;
    int *finish;
    int *eos;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    float m24;
    int rest[6];
    Ctx()
    {
        start = 0;
        finish = 0;
        eos = 0;
        m10 = 0;
        m14 = 0;
        m18 = 1;
        m1C = 1;
        m20 = 3;
        m24 = 1.0f;
    }
    ~Ctx() { Holder h(start); }
};

extern "C" void func_002C5338(Ctx *c);
extern "C" int func_002C5698(Ctx *c, void *arg);

extern "C" int func_002C5828(void *arg) {
    Ctx c;
    func_002C5338(&c);
    return func_002C5698(&c, arg);
}
