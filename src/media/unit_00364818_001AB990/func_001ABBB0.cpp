#include "types.h"

extern "C" void func_001AF600(void *);

extern "C" void func_001ABBB0(char *arg0) {
    func_001AF600(*(void **)(arg0 + 0x4));
}
