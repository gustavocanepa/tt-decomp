/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;

/* Three floats written as one 64-bit and one 32-bit word (no 16-byte alignment). */
struct Point {
    u64 xy;
    u32 z;
} __attribute__((packed));

struct Vec3 {
    f32 x, y, z;
};

struct Plane {
    f32 x, y, z, d;
};

struct VEntry {
    s16 delta;
    s16 index;
    Vec3 (*fn)(void *self, f32 t);
};

struct Obj {
    VEntry *vtbl;
};

struct RaceCarModel {
    Obj *obj;
};

extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_0041EBA8(Obj *o, f32 t);

/* The plane through the model's point at t whose normal is the matrix row vf29. */
extern "C" void RaceCarModel__virtual_37(RaceCarModel *self, Plane *out, f32 t) {
    u64 lo;
    u32 hi;
    Obj *obj;
    VEntry *e;

    func_00473050();
    func_004751FC();
    func_0041EBA8(self->obj, t);
    __asm__ volatile("vnop");
    __asm__ volatile("qmfc2.ni %0, $vf29" : "=r"(lo));
    __asm__("pcpyud %0, %1, %1" : "=r"(hi) : "r"(lo));
    ((Point *)out)->xy = lo;
    ((Point *)out)->z = hi;
    func_004730A8();
    obj = self->obj;
    e = &obj->vtbl[8];
    Vec3 p = e->fn((char *)obj + e->delta, t);
    out->d = -(out->x * p.x + out->y * p.y + out->z * p.z);
}
