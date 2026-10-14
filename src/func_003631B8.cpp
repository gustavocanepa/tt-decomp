/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct Fx { char pad[0x28]; f32 f28; };
struct Self {
    char pad0[0x18];
    f32 f18;
    f32 f1C;
    char pad20[0x18C - 0x20];
};

extern "C" void AutomaticFader__update(void *) throw();
extern "C" void func_00359DE0(void *, f32) throw();
extern "C" void RaceEventDisplay__update(void *, f32) throw();
extern "C" void AutomaticFader__fadein(void *, f32) throw();
extern "C" void AutomaticFader__fadeout(void *, f32) throw();

extern "C" void RaceTooltipDisplay__update(char *self, f32 dt) {
    Fx *fx = (Fx *)(self + 0x18C);
    Self *s = (Self *)self;
    f32 cur = s->f1C;
    f32 diff = s->f18 - cur;
    if (diff != 0.0f) {
        f32 c = 0x1.47ae14p-7f;
        f32 step = diff * 10.0f * dt;
        if (__builtin_fabsf(step) < c) {
            if (0.0f <= step) {
                step = minf(diff, c);
            } else {
                step = maxf(diff, -c);
            }
        }
        s->f1C = cur + step;
    }
    AutomaticFader__update((self + 0x20));
    func_00359DE0(self + 0x3C, dt);
    RaceEventDisplay__update(fx, dt);
    if (fx->f28 == 0.0f) {
        return AutomaticFader__fadein((self + 0x20), 0x1.999998p-3f);
    }
    AutomaticFader__fadeout((self + 0x20), 0x1.999998p-4f);
}
