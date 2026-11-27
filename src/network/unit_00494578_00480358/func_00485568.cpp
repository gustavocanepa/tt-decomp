/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot {
    int m0;
    int m4;
};
struct Rec {
    char c0;
    char pad1[3];
    short s4;
    short s6;
};
struct O {
    char pad[0x20];
    Slot slot[1];
};
extern "C" void func_004825C8(O *, Rec *, char *, int) throw();
extern "C" void func_00482820(O *) throw();
extern "C" Rec *func_004834E8(O *) throw();
extern "C" void func_00483628(O *, Rec *, char *, int) throw();

extern "C" int func_00485568(O *o) {
    if (*(int *)((char *)o + 0x864) != 0) {
        return 1;
    }
    Slot *s = (Slot *)((char *)o + (1 - *(int *)((char *)o + 0x85C)) * 0x41C + 0x24);
    char buf[0x200];
    switch (s->m0) {
    case 0:
        return 0;
    case 1:
        s->m4 = 1;
        func_00482820(o);
        s->m0 = 2;
        return 1;
    case 2: {
        Rec *p = func_004834E8(o);
        func_004825C8(o, p, buf, 0x100);
        func_00483628(o, p, buf, p->s6 - p->s4);
        p->c0 = 4;
        return 1;
    }
    default:
        return 1;
    }
}
