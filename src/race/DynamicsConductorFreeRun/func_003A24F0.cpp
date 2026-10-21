/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Ev { char pad[0x968]; u32 t; };
struct Car { char pad[0x5D7]; u8 f; };
struct Car2 { char pad[0x104 + 0x614]; s32 v; };

extern "C" s32 func_002F04D8(void *, s32);
extern "C" void func_00305370(void *, s32, s32);
extern "C" void func_003053E8(void *, s32, s32);
extern "C" void func_00305DD8(void *, s32, s32, s32, u32, u32);
extern "C" void func_0030AA58(void *);

extern "C" void func_003A24F0(Ev **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5) {
    Ev *ev = *arg0;
    Car *c = (Car *)func_002F04D8(arg0, arg1);
    char *q = (char *)c + 0x104;
    u32 f = c->f;
    if (f == 0) {
        u32 t = ev->t;
        if (t != 0x157529FF) {
            func_003053E8(ev, arg1, arg5 - t);
        }
        if (arg5 < t) {
            func_00305370(ev, arg1, 2);
        }
    }
    func_00305DD8(arg0, arg1, arg2, arg4, arg5, c->f);
    func_0030AA58(c);
    *(s32 *)(q + 0x630) = arg4;
}
