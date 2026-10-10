#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0031A718_arg0 {
    char pad0[0xA80];
    f32 unkA80;
    char padA84[0x10];
    f32 unkA94;
};

f32 func_0031A718(struct func_0031A718_arg0 *arg0) {
    return arg0->unkA94 / arg0->unkA80;
}
