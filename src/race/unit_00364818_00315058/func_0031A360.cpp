struct Vec {
    float x, y, z;
};

struct Obj {
    char pad0[0x34];
    Vec m34;
    char pad40[0x60 - 0x40];
    char m60[0x20];
    int m80;
    char pad84[0xAC - 0x84];
    float mAC;
};

struct Src {
    char pad0[0x34];
    float m34;
};

extern "C" void func_00319760(Obj *o, void *m, int a);
extern "C" void func_00552A68(void *m, Vec *v);
extern "C" void func_00318E60(Obj *o, float x, float y);

extern "C" void func_0031A360(Obj *o, Src *s) {
    o->mAC -= s->m34 * 0x1.11111p-4f;
    func_00319760(o, o->m60, o->m80);
    func_00552A68(o->m60, &o->m34);
    func_00318E60(o, o->m34.x, o->m34.z);
}
