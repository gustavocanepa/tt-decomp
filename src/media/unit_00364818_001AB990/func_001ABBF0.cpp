#include "types.h"

extern "C" void func_001AF6C0(void *);

extern "C" void func_001ABBF0(char *arg0) {
    func_001AF6C0(*(void **)(arg0 + 0x4));
}
