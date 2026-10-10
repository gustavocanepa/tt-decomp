struct Obj {
    float base;
    float scaled;
    float maxValue;
    float minValue;
    float gain;
    char sub[0x104];
    float limit;
    char sub2[4];
};

extern "C" float func_003174F8(float x);
extern "C" void func_0032E228(void *sub, float x);
extern "C" void func_0032E0A0(void *sub, void *arg);

extern "C" void func_0032E2F8(Obj *o, void *arg, float x, float unused, float limit) {
    o->base = x;
    o->scaled = func_003174F8(x);
    o->maxValue = 600.0f;
    o->minValue = -60.0f;
    o->gain = 1.0f;
    o->limit = limit;
    func_0032E228(o->sub, x);
    func_0032E0A0(o->sub2, arg);
}
