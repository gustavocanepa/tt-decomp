struct Obj;
extern "C" float func_002F9A78(Obj *o);
extern "C" void func_002F9B38(Obj *o, float d);
extern "C" void func_002F9A58(Obj *o, float v);

extern "C" float func_002F9C00(Obj *o, float x) {
    float have = func_002F9A78(o);
    func_002F9B38(o, -x);
    if (have < x) {
        float d = x - have;
        have = 0.0f;
        x -= d;
    } else {
        have -= x;
    }
    func_002F9A58(o, have);
    return x;
}
