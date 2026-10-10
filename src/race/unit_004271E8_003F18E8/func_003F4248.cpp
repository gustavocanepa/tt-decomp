struct Mat44 {
    float m[4][4];
};

struct Rot {
    float v[4];
    Rot() __asm__("func_004519B0");
    void toMatrix(Mat44 *out, float x, float y, float z) __asm__("func_004511B0");
};

struct Elem {
    char data[0x40];
    void set(Mat44 *m) __asm__("func_004504A0");
};

struct Obj {
    int m0;
    int m4;
    int cur;
    Elem elems[1];
};

extern "C" void func_003F4248(Obj *o) {
    Rot r;
    Mat44 m;
    r.toMatrix(&m, 0.0f, 0.0f, 0.0f);
    o->elems[o->cur].set(&m);
}
