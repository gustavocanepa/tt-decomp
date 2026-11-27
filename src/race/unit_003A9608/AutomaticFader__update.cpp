/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Fader {
    float val;
    char pad4[4];
    float f8;
    float fC;
    float f10;
    float f14;
    s32 state;
};
static inline float fmaxf_(float a, float b) { __asm__("max.s %0, %1, %0" : "+f"(b) : "f"(a)); return b; }
static inline float fminf_(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" float AutomaticFader__update(struct Fader *self, float dt) {
    float d = 0.0f;
    switch (self->state) {
    case 0:
        self->f14 = self->f14 - dt;
        if (self->f14 < 0.0f) {
            self->state = 1;
            self->f14 = self->f14 + self->f8;
        }
        d = -self->f10;
        break;
    case 1:
        if (self->f8 >= 0.0f) {
            self->f14 = self->f14 - dt;
            if (self->f14 < 0.0f) self->state = 2;
        }
        d = self->fC;
        break;
    case 2:
        *(s32 *)&self->f14 = 0;
        d = -self->f10;
        break;
    }
    d = d * dt;
    float v = self->val;
    float s = v + d;
    float m = fmaxf_(s, 0.0f);
    return self->val = fminf_(m, 1.0f);
}
