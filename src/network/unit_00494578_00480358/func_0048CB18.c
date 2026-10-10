#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CB18_arg0 {
    char pad0[0x7C];
    void *unk7C;
};

void func_0048CB18(struct func_0048CB18_arg0 *arg0, void *arg1) {
    arg0->unk7C = (void *) ((arg1 != NULL) ? arg1 : arg0);
}
