#include "types.h"

/* Classes named after their constructors (func_00123F58, func_00128470); their sizes are only
   bounded by the frame (the first takes 0x11-0x20 bytes, the second at most 0x10). */
struct func_00123F58 {
    void *p;
    char data[0x1C];
    func_00123F58(void *src);
    ~func_00123F58() { func_00123F00(this, 2); }
    static void func_00123F00(func_00123F58 *self, s32 flags);
};

struct func_00128470 {
    void *p;
    char data[0xC];
    func_00128470(void *src);
    ~func_00128470() { func_00128418(this, 2); }
    static void func_00128418(func_00128470 *self, s32 flags);
};

extern "C" void func_00126CB0(void *obj, func_00128470 *arg);

extern "C" void MCarFace__set_car_garage(void *self, void *a, void *b, void *c) {
    func_00123F58 x(a);
    void *obj = x.p;
    func_00128470 y(c);
    func_00126CB0(obj, &y);
}
