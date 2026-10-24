#include "types.h"

struct VE3784B8 { s16 delta; s16 index; void *fn; };

extern "C" int func_003A8850(s32, void *, void *, f32, f32, f32, f32);

extern "C" void func_00321098(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    char sp[0x40];
    struct VE3784B8 *e;
    void *obj;
    s32 s2;
    struct VE3784B8 * e_2 = (struct VE3784B8 *)(*(char **)arg0 + 0x208);
    obj = ((void *(*)(void *))e_2->fn)((char *)arg0 + e_2->delta);
    s2 = *(s32 *)((char *)arg0 + 0xF04);
    struct VE3784B8 * e_2_2 = (struct VE3784B8 *)(*(char **)obj + 0x78);
    ((void (*)(void *, void *, void *))e_2_2->fn)((char *)obj + e_2_2->delta, sp, (char *)arg0 + 0xA80);
    func_003A8850(s2, sp, (char *)obj + 0x100, fparg0, fparg1, fparg2, fparg3);
}
