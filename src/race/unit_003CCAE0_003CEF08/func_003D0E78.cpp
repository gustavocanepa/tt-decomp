struct Elem {
    char pad[0x320];
};

struct Obj {
    Elem items[6];
};

extern "C" void func_003D0618(Elem *e);
extern "C" void PitmenTiny__clear(Obj *o);

extern "C" void func_003D0E78(Obj *o) {
    Elem *e = o->items;
    for (int i = 5; i != -1; i--) {
        func_003D0618(e);
        e++;
    }
    return PitmenTiny__clear(o);
}
