struct In {
    char pad[0xC];
    virtual int v00(); virtual int v01();
};
extern "C" In *func_003FD748(int);
extern "C" int func_001668B8(char *arg0) {
    In *o = func_003FD748(*(int *)(arg0 + 0x10));
    return o->v01();
}
