typedef long s64;

struct Obj {
    s64 a;
    s64 b;
    s64 c;
    s64 d;
};

extern "C" int func_004109F8(s64 arg0, struct Obj *out);

extern "C" int func_004107B0(s64 arg0, struct Obj *arg1) {
    struct Obj obj;
    if (func_004109F8(arg0, &obj)) {
        arg1->a = obj.a;
        arg1->b = obj.b;
        arg1->c = obj.c;
        arg1->d = obj.d;
        return 1;
    }
    return 0;
}
