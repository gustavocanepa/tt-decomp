struct Obj {
    char padDC[0xDC];
    int unkDC;
    int unkE0;
    int unkE4;
};

extern "C" void func_0037A660(Obj *arg0) {
    arg0->unkDC = 0;
    arg0->unkE0 = 0;
    arg0->unkE4 = 0;
}
