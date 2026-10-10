typedef long s64;

struct Obj {
    int f0;
    int f4;
    s64 id;
};

extern "C" void *D_00585CA0;
extern "C" int func_00411258(void *mgr, int id, int arg);

extern "C" bool func_00410C68(Obj *o, int arg) {
    s64 id = o->id;
    if (id == -1) {
        return false;
    }
    return func_00411258(D_00585CA0, (int)(id & 0xFFFFFFFF), arg) != 0;
}
