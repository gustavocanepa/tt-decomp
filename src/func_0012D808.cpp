typedef int s32;
extern "C" s32 func_001324D8(s32);extern "C" s32 func_0012D798(s32);extern "C" s32 func_00408B58(s32);extern "C" s32 func_0040D170(s32);


extern "C" void func_00128418(s32 *arg0, s32 arg1);
extern "C" void func_00128470(s32 *arg0, void *arg1);
extern "C" s32 func_00146758(s32 arg0);
extern "C" void func_0029CEF0(s32 *arg0, s32 arg1);
extern "C" void func_0029EA18(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void MCarGarage__isNAtune(s32 *arg0,void *arg1) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_00128470(sp,arg1);
    {
        s32 car=func_001324D8(sp[0]);s32 super=func_0012D798(car);s32 turbo=func_0040D170(func_00408B58(car));s32 t=super?0:!turbo;
        p1 = sp10;
        func_0029EA18(p1, t);
    }
    if (arg0 != p1) {
        temp_s0 = *p1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_a0 = *arg0;
        if (temp_a0 != 0) {
            func_002C1050(temp_a0);
        }
        *arg0 = temp_s0;
    }
    func_0029CEF0(p1, 2);
    func_00128418(sp, 2);
}
