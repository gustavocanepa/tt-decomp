#include "types.h"

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct FontManager;
extern FontManager *D_00586EF4;

extern "C" void func_0045EEE0(FontManager *m);
extern "C" void func_0045EF78(FontManager *m, f32 r, f32 g, f32 b, f32 a);

extern "C" void func_00415BB0(f32 r, f32 g, f32 b, f32 a) {
    func_0045EEE0(D_00586EF4);
    func_0045EF78(D_00586EF4, 0.0f, 0.0f, 0.0f, minf(maxf((a - 0.25f) * 0x1.555554p+0f, 0.0f), 1.0f));
}
