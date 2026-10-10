struct Obj {
    char pad[0x1C];
    int active;
    int busy;
};

extern "C" unsigned int func_003EB020(void *pad);
extern "C" void func_002D8C18(Obj *o, int what);

extern "C" void func_002D8718(Obj *o, void *pad) {
    if (o->active == 0 || o->busy != 0)
        return;
    unsigned int mask = 0x3800E;
    unsigned int buttons = func_003EB020(pad);
    if (buttons & 1)
        func_002D8C18(o, 1);
    if (buttons & mask)
        func_002D8C18(o, 2);
}
