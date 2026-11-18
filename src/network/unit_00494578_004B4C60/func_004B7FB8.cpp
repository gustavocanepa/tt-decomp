/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004B7EF0() throw();
extern "C" int func_004F4138(int,int);
extern "C" void func_004F41F0(int);
extern "C" void func_004F4348(int);
extern "C" int func_004FA500(int,void *,int);
extern "C" int func_004FA520(int,int);
extern "C" int func_005038D8();
extern int D_0059835C;
extern char D_00598360[];
struct Flag { int v; };
extern volatile Flag D_00598354;
extern char D_004B7F60[];
static inline int active(volatile Flag *const p) { return p->v; }
extern "C" void func_004B7FB8() {
    int *count = &D_0059835C;
    *count = 0;
    { int *q = (int *)D_00598360; *q = func_004F4138(0,255); }
    int saved = func_004FA500(2,D_004B7F60,0);
    while (active(&D_00598354)) {
        func_004F4348(*(int *)D_00598360);
        int enabled = func_005038D8();
        --*count;
        if (enabled) __asm__ volatile("ei");
        func_004B7EF0();
    }
    int *q = (int *)D_00598360;
    func_004F4348(*q);
    int enabled = func_005038D8();
    --D_0059835C;
    if (enabled) __asm__ volatile("ei");
    func_004FA520(2,saved);
    func_004F41F0(*q);
}
