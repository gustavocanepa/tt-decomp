struct Obj {
    int m0;
    int mode;
    char pad8[8];
    float scale;
    char pad14[0x18];
    void *src;
};

extern "C" float func_00205D10(void *p);
extern "C" float func_00205D70(void *p);

extern "C" float func_00276008(Obj *o) {
    if (o->src == 0)
        return o->scale;
    float v;
    if (o->mode)
        v = func_00205D10(o->src);
    else
        v = func_00205D70(o->src);
    return v / o->scale;
}
