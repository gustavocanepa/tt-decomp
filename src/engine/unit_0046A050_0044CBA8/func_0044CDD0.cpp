struct Obj {
    void *data;
};

extern "C" int func_0044CCF0(Obj *o, void *key);
extern "C" int func_0044CD98(Obj *o, int index, void *value);

extern "C" int func_0044CDD0(Obj *o, void *key, void *value) {
    if (o->data == 0)
        return 0;
    return func_0044CD98(o, func_0044CCF0(o, key), value);
}
