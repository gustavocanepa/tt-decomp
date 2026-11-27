#include "types.h"

struct Handle {
    s32 obj;
    char pad4[0xC];
};

extern "C" void func_00128470(Handle *h, void *src);
extern "C" void func_00128418(Handle *h, s32 flags);
extern "C" void func_00132460(s32 obj);
extern "C" void func_001324A8(s32 obj);

extern "C" void MCarGarage__beginSetting(void *self, void *src) {
    Handle h;
    func_00128470(&h, src);
    func_00132460(h.obj);
    func_00128418(&h, 2);
    func_00128470(&h, src);
    func_001324A8(h.obj);
    func_00128418(&h, 2);
}
