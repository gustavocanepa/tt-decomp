struct Obj {
    char pad[0x10];
    int m10;
    int m14;
    int state;
};

extern "C" void func_001FC5C0(Obj *o) {
    if (o->state != 1)
        return;
    switch (o->m14) {
    case 0:
        o->m10 = 0;
        o->state = 3;
        break;
    case 1:
        o->state = 2;
        break;
    case 2:
        o->state = 2;
        break;
    }
}
