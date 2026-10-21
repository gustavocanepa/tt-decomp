typedef int s32;
extern "C" void func_00202788(void *, int);
extern "C" void func_002027E0(void *, void *);
extern "C" void func_00205E20(void *, s32 *, s32 *);
extern "C" void *func_00257940(void *);
extern "C" void func_00257990(void *, void *, s32);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A9CF0(void *, s32);

struct W {
    char pad[0xE4];
    s32 unkC0;
    s32 unkC4;
};

extern "C" void func_002570F0(W *arg0, void *arg1, s32 arg2) {
    s32 sp0[8];
    s32 sp20[4];
    if (arg2 != 0) {
        func_002A9CF0(sp20, arg2);
        func_002027E0(sp0, sp20);
        func_002A75A8(sp20, 2);
        func_00257990(arg0, arg1, sp0[0]);
        func_00205E20(func_00257940(arg0), &arg0->unkC0, &arg0->unkC4);
        func_00202788(sp0, 2);
        return;
    }
    func_00257990(arg0, arg1, arg2);
}
