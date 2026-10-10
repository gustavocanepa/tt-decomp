extern float D_00585D38;

struct Obj {
    char pad[8];
    float m8;
    char vC[1];
};

extern "C" float func_00420430(void *p, float x);

extern "C" int func_00420470(Obj *o) {
    float d = func_00420430(o->vC, o->m8);
    float limit = D_00585D38;
    int level = 0;
    if (!(limit < d)) {
        level = 1;
        if (!(limit * 0.5f < d)) {
            level = 2;
            if (!(limit * 0.25f < d))
                level = 3;
        }
    }
    return level;
}
