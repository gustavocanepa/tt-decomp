/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;
extern "C" {
int func_004BCAA0(void *, s32);
void func_004AEB30(void *);
void func_004F8588(void *, void *, s32);
void func_004FA840(void *);
void func_004FA860(void *);
}
extern void *PDISTD__global_font_manager_;
struct Obj {
    char pad[0x22C];
    s32 f22C;
    s32 f230;
    s32 f234;
    s32 f238;
    s32 f23C;
    char p240[0x320 - 0x240];
    char p320[0x404 - 0x320];
    s32 f404;
};

extern "C" s32 func_004BC8B8(Obj *o, void *data, s32 a, s32 b, s32 c) {
    func_004BCAA0(o, 0);
    func_004FA860(PDISTD__global_font_manager_);
    o->f22C = 1;
    o->f230 = a;
    o->f234 = b;
    o->f238 = c;
    o->f23C = 1;
    if (data != 0) {
        o->f23C = 0;
        func_004F8588(o->p240, data, 0x80);
    }
    o->f404 = 2;
    func_004FA840(PDISTD__global_font_manager_);
    func_004AEB30(o->p320);
    return 0;
}
