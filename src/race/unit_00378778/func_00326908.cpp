struct Step {
    float limit;
    int id;
};

extern Step D_00583E40[];
extern Step D_00583E60[];

extern "C" int func_00326908(int mode, float *rate, float x) {
    Step *s = D_00583E40;
    if (mode)
        s = D_00583E60;
    *rate = 0.0f;
    if (x < *rate)
        return s->id;
    for (;; s++) {
        if (s->limit < *rate)
            return s->id;
        if (x < s->limit) {
            *rate = 1.0f / 60.0f;
            return s->id;
        }
    }
}
