typedef int s32;
typedef float f32;

struct Obj;
struct S_0027B3E8;

extern "C" void func_002198D0(void *arg0, int arg1);
extern "C" void func_00219928(void *arg0);
extern "C" void func_0021A888(struct S_0027B3E8 *arg0, f32 arg1);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_00299B08(void *arg0, void *arg1);
extern "C" float func_0029B188(struct Obj *arg0);

extern "C" void func_0021A018(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];

    s32 s0 = arg3;
    func_00219928(buf0);
    s32 *p1 = buf1;
    func_00299B08(p1, (void *)s0);
    s32 base0 = buf0[0];
    f32 result = func_0029B188((struct Obj *)p1[0]);
    func_0021A888((struct S_0027B3E8 *)base0, result);
    func_00299AB0(p1, 2);
    func_002198D0(buf0, 2);
}
