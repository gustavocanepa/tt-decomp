/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Mutex { s32 w; };
extern "C" void func_004A4D68(Mutex *);
extern "C" void func_004A4DD8(Mutex *);

struct Guard {
    Mutex *m;
    Guard(Mutex *mx) : m(mx) { func_004A4D68(m); }
    ~Guard() { func_004A4DD8(m); }
};

struct Range { s32 a; s32 b; s32 c; void clear() { c = 0; b = 0; a = 0; } };
struct Obj { char pad[0x10]; Range r; char pad1C[0x104]; Mutex mutex; };

extern "C" void func_00543A30(Obj *o) {
    Guard g(&o->mutex);
    o->r.clear();
}
