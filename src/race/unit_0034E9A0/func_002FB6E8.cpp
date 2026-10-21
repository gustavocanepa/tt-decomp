struct Obj {
    char pad0[0x77B];
    unsigned char flag;
};

extern "C" short func_002E4CB0(Obj *arg0);
extern "C" unsigned func_002FB6B8(char *a, char *b);

extern "C" int func_002FB6E8(int arg0, Obj *arg1) {
    if (!func_002E4CB0(arg1))
        return 0;
    if (arg1->flag == 1)
        return 0;
    return func_002FB6B8((char *)arg0, (char *)arg1);
}
