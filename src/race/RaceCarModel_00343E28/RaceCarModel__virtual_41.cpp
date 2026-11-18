/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;

/* Three floats written as one 64-bit and one 32-bit word (no 16-byte alignment). */
struct Point {
    u64 xy;
    u32 z;
} __attribute__((packed));

struct Mount {
    f32 x, y, z;
    char pad[0xC];
};

struct ModelData {
    char pad[0x3C];
    Mount *mounts;
};

struct Obj;

struct RaceCarModel {
    Obj *obj;
    char pad4[0x14];
    void *handle;
};

extern "C" ModelData *func_0041AAE0(void **handle);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_004755EC(f32 x, f32 y, f32 z);
extern "C" void func_0041EAC8(Obj *o, f32 f);
extern "C" void func_0041EB10(Obj *o, f32 f);

/* World position of mount point i of the car model, through the VU0 matrix stack (vf31 = translation). */
extern "C" void RaceCarModel__virtual_41(RaceCarModel *self, s32 i, Point *out) {
    ModelData *data;
    Mount *m;
    u64 lo;
    u32 hi;

    data = func_0041AAE0(&self->handle);
    if (data == 0)
        return;
    m = &data->mounts[i];
    func_00473050();
    func_004751FC();
    func_0041EAC8(self->obj, 0.0f);
    func_0041EB10(self->obj, 0.0f);
    func_004755EC(m->x, m->y, m->z);
    __asm__ volatile("qmfc2.ni %0, $vf31" : "=r"(lo));
    __asm__("pcpyud %0, %1, %1" : "=r"(hi) : "r"(lo));
    out->xy = lo;
    out->z = hi;
    func_004730A8();
}
