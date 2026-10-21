struct Key { float v[17]; };
struct Obj { int field0; Key keys[2]; int current; };
extern "C" void func_00475638(float, float, float);
extern "C" void func_00468C10(float, float, float, float);
extern "C" void func_002DD618(Obj *o, float t) {
    float u = 1.0f - t;
    int i = o->current;
    float *p = o->keys[i].v + 9;
    o = (Obj *)((char *)o + (1-i) * 0x44);
    float size = p[1];
    float blend = o->keys[0].v[9] * t + p[0] * u;
    func_00475638(size, 1.0f / size, 1.0f);
    func_00468C10(blend, size, p[2], p[3]);
}
