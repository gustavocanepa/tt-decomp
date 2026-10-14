/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };
struct Obj {
    char pad[8];
    short flags, length;
    Vec3 position;
    float one;
    Vec3 velocity;
    float inverse, factor;
    Vec4 color;
    float value, initial;
    int kind;
};
static inline float root(float x) {
    float result;
    __asm__("sqrt.s %0, %1" : "=f"(result) : "f"(x));
    return result;
}
extern "C" void func_00392200(Obj *o, Vec3 *p, Vec3 *v, Vec4 *c, int kind, float mass, float factor, float value) {
    o->flags = 0;
    o->position.x = p->x;
    o->position.y = p->y;
    o->position.z = p->z;
    o->one = 1.0f;
    o->velocity.x = v->x;
    o->velocity.y = v->y;
    o->velocity.z = v->z;
    o->inverse = 1.0f / mass;
    o->factor = factor;
    o->color.x = c->x;
    o->color.y = c->y;
    o->color.z = c->z;
    o->color.w = c->w;
    o->value = value;
    o->initial = value;
    o->kind = kind;
    float x = v->x, y = v->y, z = v->z;
    int len = (int)(root(x*x + y*y + z*z) * 1024.0f);
    if (len <= 0x7FFF) {
        o->length = len;
        return;
    }
    o->length = 0x7FFF;
}
