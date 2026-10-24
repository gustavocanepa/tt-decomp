struct S {
    int type;
    int flag;
};

extern "C" void func_0043D810(S *arg0, int arg1);
extern "C" float func_0043E0B0(S *arg0);

extern "C" void func_0043F050(S *arg0) {
    if (arg0->type == 5) {
        arg0->flag = arg0->flag != 1;
    } else {
        if (func_0043E0B0(arg0) == 0.0f) {
            func_0043D810(arg0, 1);
        } else {
            return func_0043D810(arg0, 0);
        }
    }
}
