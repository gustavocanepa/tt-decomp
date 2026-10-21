struct Obj {
    char pad0[0x108];
    int index;
};

extern "C" int func_004A8268(const char *a, const char *b);
extern const char *D_00579C60[];

extern "C" void func_0017C8F8(Obj *o, const char *name) {
    for (int i = 0; i < 9; i++) {
        if (func_004A8268(name, D_00579C60[i]) == 0) {
            o->index = i;
            return;
        }
    }
    o->index = 0;
}
