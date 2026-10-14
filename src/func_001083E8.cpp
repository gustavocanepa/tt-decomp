/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef unsigned long u64;

struct Elem { char pad[0x20]; u64 bits; };
struct Q { char pad[0x18]; Elem *elems; };
struct Self { char pad[0x70]; s32 idx; f32 scale; };

extern Q *D_00579744;

extern "C" void func_00104C88(void *);
extern "C" s32 func_00467728(void *);
extern "C" void func_0046AC48(void *);
extern "C" void func_00470B48(s32);
extern "C" void func_00470E60(s32);
extern "C" void func_00474288(s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_00478C98(s32);
extern "C" s32 func_00478F40(f32, f32, f32);

extern "C" void func_001083E8(Self *self, void *arg1) {
    func_00104C88(arg1);
    func_00467728(D_00579744);
    func_00478C98(5);
    func_00478C98(4);
    func_00478C98(6);
    func_00470B48(0);
    func_00470E60(1);
    Elem *e = D_00579744->elems + self->idx;
    func_0046AC48(e);
    u64 b = e->bits;
    f32 s = self->scale;
    s32 w = (s32)(((b >> 14) & 0x3FF) + 1);
    s32 h = (s32)(((b >> 34) & 0x3FF) + 1);
    s32 x = (0x280 - w) >> 1;
    s32 y = (0x1C0 - h) >> 1;
    func_00478F40(s, s, s);
    func_00474288(x, y, x + w, y + h, 0, 0, w, h);
}
