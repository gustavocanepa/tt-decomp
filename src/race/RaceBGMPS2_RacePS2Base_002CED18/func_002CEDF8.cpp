#include "types.h"
extern "C" s32 func_0033BE18(void *);
extern "C" void func_0033C4E0(void *);
extern "C" void func_0036C308(void *, void *);
extern "C" s32 func_002CEDF8(char *arg0) {
    if (*(s32 *)(arg0 + 0xE40) != 0) {
        func_0033C4E0(arg0);
        return 0;
    }
    func_0036C308(arg0 + 0xD018, *(void **)(arg0 + 0x6C));
    return func_0033BE18(arg0);
}
