struct Obj {
    float m0;
    float m4;
    float m8;
};

extern "C" float func_004AFC98(int mode, float t, float range);

extern "C" Obj *func_004AFD98(Obj *o, float t, float scale, float lo, float hi) {
    float d = t - o->m8;
    d = func_004AFC98(1, d - lo, hi - lo) + lo;
    o->m0 += d * scale;
    return o;
}
