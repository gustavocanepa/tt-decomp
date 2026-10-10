typedef long s64;

struct Obj {
    char pad[0xA0];
    s64 unkA0;
};

extern "C" int func_0040EE68(Obj *arg0, s64 arg1);

extern "C" int func_00565B78(Obj *arg0) {
    return func_0040EE68(arg0, arg0->unkA0);
}
