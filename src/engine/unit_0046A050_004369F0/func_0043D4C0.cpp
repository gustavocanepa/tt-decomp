struct Val {
    int type;
    void *ptr;
};

extern "C" void func_0043D4C0(Val *v) {
    if (v->type == 3) {
        ++*(unsigned short *)v->ptr;
    } else if (v->type == 13 || v->type == 7) {
        ++*(int *)v->ptr;
    }
}
