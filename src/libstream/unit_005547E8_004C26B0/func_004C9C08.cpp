#include "types.h"

extern "C" void *func_004F6678(void *, s32, s32);
extern "C" void *func_004F64C4(void *, const void *, s32);

extern "C" void func_004C9C08(void *dst, u16 *src) {
    func_004F6678(dst, 0, 0x24);
    func_004F64C4(dst, src, *src);
}
