#include "types.h"

extern s32 D_00582D44;
extern "C" void *func_002E86D0(void *);
extern "C" void *func_004F64C4(void *, const void *, unsigned int);

extern "C" void func_002E8728(void *dst, void *src) {
    void *d = func_002E86D0(dst);
    func_004F64C4(d, func_002E86D0(src), D_00582D44);
}
