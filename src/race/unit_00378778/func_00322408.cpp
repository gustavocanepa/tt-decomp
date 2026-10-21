/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" f32 func_003175D8(f32, f32, f32) throw() __attribute__((const));                   /* extern */
extern "C" void func_004755EC(f32, f32, f32);               /* extern */
extern "C" void func_00475730(f32);                         /* extern */
extern "C" void func_00475758(f32);                         /* extern */
extern "C" void func_00475780(f32);                         /* extern */

struct Vec { float x, y, z, pad; };
static inline void set(float *out, float value) { *out = value; }
static inline float get(const float *p) { return *p; }
static inline void linear(float *ox, float *oy, float *oz, float x, float y, float z, float bx, float by, float bz, float t) {
    float dx, dy, dz;
    dx = bx - x; dy = by - y; dz = bz - z;
    *ox = x + dx*t; *oy = y + dy*t; *oz = z + dz*t;
}
extern "C" void func_00322408(char *arg0, float t) {
    Vec a, b, c, d, e, f;
    a.x = func_003175D8(M2C_FIELD(arg0,float*,0x64), M2C_FIELD(arg0,float*,0xD0),t);
    { float result = func_003175D8(M2C_FIELD(arg0,float*,0x68), M2C_FIELD(arg0,float*,0xD4),t); set(&a.y,result); }
    { float result = func_003175D8(M2C_FIELD(arg0,float*,0x6C), M2C_FIELD(arg0,float*,0xD8),t); set(&a.z,result); }
    linear(&d.x, &d.y, &d.z, M2C_FIELD(arg0,float*,0x58), M2C_FIELD(arg0,float*,0x5C), M2C_FIELD(arg0,float*,0x60), M2C_FIELD(arg0,float*,0xC4), M2C_FIELD(arg0,float*,0xC8), M2C_FIELD(arg0,float*,0xCC), t);
    b.x = func_003175D8(M2C_FIELD(arg0,float*,0x4C), M2C_FIELD(arg0,float*,0xB8),t);
    { float result = func_003175D8(M2C_FIELD(arg0,float*,0x50), M2C_FIELD(arg0,float*,0xBC),t); set(&b.y,result); }
    { float result = func_003175D8(M2C_FIELD(arg0,float*,0x54), M2C_FIELD(arg0,float*,0xC0),t); set(&b.z,result); }
    linear(&e.x, &e.y, &e.z, M2C_FIELD(arg0,float*,0x40), M2C_FIELD(arg0,float*,0x44), M2C_FIELD(arg0,float*,0x48), M2C_FIELD(arg0,float*,0xAC), M2C_FIELD(arg0,float*,0xB0), M2C_FIELD(arg0,float*,0xB4), t);
    c.x = func_003175D8(M2C_FIELD(arg0,float*,0x34), M2C_FIELD(arg0,float*,0xA0),t);
    { float result = func_003175D8(M2C_FIELD(arg0,float*,0x38), M2C_FIELD(arg0,float*,0xA4),t); set(&c.y,result); }
    { float result = func_003175D8(M2C_FIELD(arg0,float*,0x3C), M2C_FIELD(arg0,float*,0xA8),t); set(&c.z,result); }
    linear(&f.x, &f.y, &f.z, M2C_FIELD(arg0,float*,0x28), M2C_FIELD(arg0,float*,0x2C), M2C_FIELD(arg0,float*,0x30), M2C_FIELD(arg0,float*,0x94), M2C_FIELD(arg0,float*,0x98), M2C_FIELD(arg0,float*,0x9C), t);
    func_00475780(get(&a.z)); func_00475730(get(&a.y)); func_00475758(a.x);
    func_004755EC(get(&d.x),get(&d.y),get(&d.z));
    func_00475780(get(&b.z)); func_00475730(get(&b.y)); func_00475758(b.x);
    func_004755EC(e.x,get(&e.y),get(&e.z));
    func_00475780(get(&c.z)); func_00475730(get(&c.y)); func_00475758(c.x);
    func_004755EC(f.x,get(&f.y),get(&f.z));
}
