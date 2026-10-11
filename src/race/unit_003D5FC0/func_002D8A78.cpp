struct Inner {
    char pad[0x60];
    int id;
};

struct Item {
    char pad[0x14];
    int value;
};

struct Obj {
    char pad0[0xC];
    Inner *inner;
    int timer;
    char pad1[0x6C - 0x14];
    int dirty;
    char pad2[0xC4 - 0x70];
    int values[8];
};

extern "C" void func_0036C1E8(int id);
extern "C" Item *func_002D8088(Obj *o);
extern "C" Item *func_002D8038(Obj *o, Item *it);
extern "C" unsigned int func_002FC298(int t);

extern "C" void func_002D8A78(Obj *o)
{
    func_0036C1E8(o->inner->id);
    int i = 0;
    for (Item *it = func_002D8088(o); it != 0; it = func_002D8038(o, it)) {
        int v = it->value;
        if (o->values[i] != v) {
            o->values[i] = v;
            o->dirty = 1;
        }
        i++;
    }
    if (func_002FC298(o->timer) < 1000) {
        o->dirty = 0;
    }
}
