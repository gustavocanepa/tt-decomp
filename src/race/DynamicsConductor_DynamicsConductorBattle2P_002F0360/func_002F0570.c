#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceCourse__getCourseLength(s32);                         /* extern */

struct func_002F0570_arg0 {
    char pad0[0x20A20];
    s32 unk20A20;
};

void func_002F0570(struct func_002F0570_arg0 *arg0) {
    RaceCourse__getCourseLength(arg0->unk20A20);
}
