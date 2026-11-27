/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xD4]; int axis; char padB4[0x20]; float scale; char padD8[0xC]; float width; float height; float offset; };
extern "C" float func_00205D10(Obj *);
extern "C" float func_00205D70(Obj *);
extern "C" float func_00278870(Obj *);
extern "C" int func_004AC5A0(void *);
extern "C" float func_0027B3F8(Obj *self) {
    float f20;
    float f22;
    float f21;
    float total;
    float neg;
    int axis = self->axis;
    if (axis == 0) f21 = self->width;
    else f21 = self->height;
    if (axis == 0) f22 = func_00205D10(self);
    else f22 = func_00205D70(self);
    f20 = f21 + func_00278870(self);
    total = f20 * (float)(func_004AC5A0((char *)self + 0xE0) - 1) + f21 * self->scale;
    neg = -self->offset;
    if (neg < 0.0f) return 0.0f;
    {
        float ratio = neg / total;
        float result = 1.0f - f22 / total;
        if (result <= ratio) return result;
        return ratio;
    }
}
