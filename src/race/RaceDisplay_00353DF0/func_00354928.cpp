typedef float f32;

struct Obj {
    char pad0[0x6C];
    f32 angle;
};

extern "C" void func_00473178(int on);
extern "C" void func_00473050(void);
extern "C" void func_004755EC(f32 x, f32 y, f32 z);

extern "C" void func_00354928(Obj *o) {
    func_00473178(1);
    func_00473050();
    func_004755EC(0.0f, -o->angle, 0.0f);
    func_00473178(0);
}
