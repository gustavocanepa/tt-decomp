/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Fn { void *fn; s32 arg; s32 pad[6]; };
struct Buf { void *ptr; s32 size; };

extern s32 D_00578EF0;
extern volatile s32 D_00578EF4;
extern char D_0061BCA0[];

extern "C" void func_00100FE8(void);
extern "C" void func_001004A0(void);
extern "C" void func_00100578(s32);
extern "C" void func_001005A0(float, float, float);
extern "C" s32 func_004A58E0(s32, s32);
extern "C" s32 func_004A53A0(s32);
extern "C" s32 func_004A56C8(Fn *, Buf *, s32);
extern "C" void func_004A5618(s32);

extern "C" void func_00101158(void) {
    Fn f;
    Buf b;
    Buf *pb = &b;
    D_00578EF4 = 0;
    f.fn = (void *)func_00100FE8;
    f.arg = 0;
    pb->ptr = D_0061BCA0;
    pb->size = 0x8000;
    s32 r = func_004A56C8(&f, pb, func_004A53A0(func_004A58E0(4, 0)));
    D_00578EF0 = r;
    func_004A5618(r);
    func_001004A0();
    func_001005A0(0.0f, 0.0f, 0.0f);
    func_00100578(2);
}
