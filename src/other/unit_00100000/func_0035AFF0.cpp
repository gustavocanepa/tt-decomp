struct Obj_003A5C68 {
    char pad0[0x10];
    void *m10;
    char pad14[4];
    void *m18;
    void *m1C;
};

extern "C" void *func_00357310(const char *name);
extern "C" char D_005F5630[];
extern "C" char D_005F5640[];
extern "C" char D_005F5650[];

extern "C" void func_0035AFF0(Obj_003A5C68 *o) {
    if (o->m10 == 0) {
        o->m10 = func_00357310(D_005F5630);
        o->m18 = func_00357310(D_005F5640);
        o->m1C = func_00357310(D_005F5650);
    }
}
