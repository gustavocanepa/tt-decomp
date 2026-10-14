/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Inner { char pad[0x18]; void *unk18; };
struct Obj {
    char pad0[8];
    f32 m8;
    f32 mC;
    char pad1[0x180 - 0x10];
    Inner *m180;
    f32 m184;
};

extern f32 D_00583D94;
extern f32 D_00583D98;
extern f32 D_00583D9C;

extern "C" f32 func_002E5E40(void *, f32);
extern "C" f32 func_002E5EA0(void *, f32);
extern "C" f32 func_002E5ED0(void *, f32);
extern "C" float func_00317438(float) throw();
extern "C" void func_0046E150(void);
extern "C" void func_0046E1B0(void);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_004752F8(void *);
extern "C" void func_004755EC(f32, f32, f32);
extern "C" void func_00475730(f32);
extern "C" void func_00475758(float);

extern "C" s32 func_00325EE0(Obj *o) {
    void *t = o->m180->unk18;
    o->m184 = func_00317438(o->m184 + 0.5f);
    func_0046E150();
    func_00473050();
    func_004751FC();
    func_004755EC(0.0f, 0.0f, -D_00583D9C);
    func_00475730(D_00583D98);
    func_00475758(o->m184);
    f32 a = -func_002E5E40(t, 0.0f);
    f32 b = -func_002E5EA0(t, 0.0f);
    func_004755EC(a, b, -func_002E5ED0(t, 0.0f));
    func_004752F8((char *)o + 0x100);
    func_004730A8();
    func_0046E1B0();
    o->m8 = D_00583D9C;
    o->mC = D_00583D94;
    return 1;
}
