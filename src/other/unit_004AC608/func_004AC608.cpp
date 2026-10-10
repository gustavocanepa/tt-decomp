struct Obj {
    int pos;
    int f4;
    int size;
    int busy;
};

extern "C" bool func_004AC5B8(Obj *o, int pos);

extern "C" bool func_004AC608(Obj *o) {
    if (o->busy != 0) {
        return false;
    }
    int next = o->pos + 1;
    if (next >= o->size) {
        return true;
    }
    return !func_004AC5B8(o, next);
}
