struct Val {
    int type;
};

extern "C" void func_0043D780(Val *v, int b);
extern "C" void func_0043F408(Val *v, int type) throw();
extern "C" float func_0043E0B0(Val *v);

extern "C" void func_0043F510(Val *v) {
    if (v->type == 10)
        return func_0043D780(v, 1);
    func_0043F408(v, 10);
    func_0043D780(v, func_0043E0B0(v) != 0.0f);
}
