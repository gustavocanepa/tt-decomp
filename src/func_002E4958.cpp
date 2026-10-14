struct Obj {
    char pad0[8];
    float value;
    char pad1[8];
    unsigned char locked;
};

extern char D_00582E98[];
extern "C" float func_002F4FB8(struct Obj *arg0);
extern "C" float func_002F4FF0(struct Obj *arg0);

extern "C" float func_002E4958(struct Obj *o)
{
    float result = 0.0f;

    if (o->locked == 0) {
        float t = func_002F4FF0((struct Obj *)D_00582E98);
        result = 1.0f;
        if (t != 0.0f) {
            float v = o->value;
            if (v < 0.0f) {
                v = v - func_002F4FB8((struct Obj *)D_00582E98);
            }
            result = v / t;
            if (result > 1.0f) {
                result = 1.0f;
            }
        }
    }
    return result;
}
