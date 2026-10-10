#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055A410_arg0 {
    char pad0[0xD40];
    s32 unkD40;
};

void *func_0055A410(void *arg0) {
    return (((struct func_0055A410_arg0 *)arg0)->unkD40 * 0x6A0) + arg0 + 0x680;
}
