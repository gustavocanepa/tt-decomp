struct Obj {
    char pad[0x24116];
    short frames;
};

extern "C" int func_003A59F0(Obj *o);

extern "C" int func_003A5A78(Obj *o) {
    if (o->frames == 0)
        return -1;
    int t = func_003A59F0(o);
    if (t == 0)
        return -1;
    return t - o->frames / 60;
}
