#include "types.h"
void *exception__structor_0(s32);
void func_0043BB88(void *a, s32 b, s32 c, s32 d);
void func_0043C9C8(void *a, char *b, void *c);
extern char D_002C62D8[];
void func_002C69E8(char *arg0) {
    char *temp_v0;
    if (*(s32 *)(arg0 + 0xC) != 0 && *(s32 *)(arg0 + 0x14) != 0 && *(s32 *)(arg0 + 0x10) == 0) {
        temp_v0 = exception__structor_0(0x19C);
        func_0043BB88(temp_v0, *(s32 *)(arg0 + 0xC), 0, *(s32 *)(arg0 + 0x14));
        *(char **)(arg0 + 0x10) = temp_v0;
        func_0043C9C8(temp_v0, D_002C62D8, arg0);
        *(s32 *)(*(char **)(arg0 + 0x10) + 0x10) = 0;
    }
}
