/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Vec3 { f32 x, y, z; };

struct Light {
    s32 flags;
    f32 intensity;
    char pad8[4];
    Vec3 color;
    char pad18[0x24 - 0x18];
};

struct Self {
    char pad0[0x94];
    Light light[2];
};

static inline void setv(Vec3 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

extern "C" void func_0035FC08(Self *self, s32 mode) {
    Light *l0 = &self->light[0];
    Light *l1 = &self->light[1];
    switch (mode) {
    case 1:
        l0->intensity = 3.0f;
        l0->flags &= ~0xFF;
        setv(&l0->color, 0.2f, 0.93f, 0.11f);
        setv(&l1->color, 0.0f, 0.0f, 0.0f);
        break;
    case 2:
        l1->intensity = 3.0f;
        l1->flags &= ~0xFF;
        setv(&l0->color, 0.0f, 0.0f, 0.0f);
        setv(&l1->color, 0.98f, 0.89f, 0.0f);
        break;
    case 3:
        l0->intensity = 3.0f;
        l0->flags &= ~0xFF;
        setv(&l0->color, 0.98f, 0.89f, 0.0f);
        setv(&l1->color, 0.0f, 0.0f, 0.0f);
        break;
    case 0:
    default:
        setv(&l0->color, 0.0f, 0.0f, 0.0f);
        setv(&l1->color, 0.0f, 0.0f, 0.0f);
        break;
    }
}
