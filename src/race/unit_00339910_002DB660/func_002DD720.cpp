struct Key { float v[17]; };

struct Obj {
    int unk0;
    Key keys[2];
    int current;
};

extern "C" void func_002DD6C8(float *out, int n, const float *a, const float *b, float t);
extern "C" void func_00468938(float a0, float a1, float a2, float a3, float a4, float a5, float a6,
                              float a7, float a8);

extern "C" void func_002DD720(Obj *o, float t) {
    float v[9];
    func_002DD6C8(v, 9, o->keys[1 - o->current].v, o->keys[o->current].v, t);
    func_00468938(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
}
