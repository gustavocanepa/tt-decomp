struct Vec3 {
    float x, y, z;
    float pad;
};

struct Obj {
    char pad0[0x6E28];
    float angle;
    float dist;
};

static inline float sqrtf_(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

extern "C" Vec3 func_00475850(const void *src);
extern "C" float func_004A6120(float a, float b);
extern const char D_00601C88[];

extern "C" void func_00445628(Obj *o) {
    Vec3 v = func_00475850(D_00601C88);
    float d = sqrtf_(v.x * v.x + v.y * v.y + v.z * v.z);
    o->angle = func_004A6120(d, 0x1.999998p-2f);
    o->dist = d;
}
