#include "types.h"
struct Arr0047F380 {
    char *base;
    s32 count;
};
struct Ctl0047F380 {
    s32 a;
    s32 b;
};
struct World0047F380 {
    char pad[0x6E14];
    struct Ctl0047F380 *ctl;
};
extern "C" void func_004461F8(char *a, void *b, f32 c);
extern "C" void func_00446390(char *a, void *b, f32 c);
extern "C" void func_00478C98(s32 a);

extern "C" void func_004460B0(struct Arr0047F380 *arg0, struct World0047F380 *arg1, f32 fparg0) {
    char *p;
    char *end;

    end = arg0->base + arg0->count * 12;
    p = arg0->base;
    while (p != end) {
        func_004461F8(p, arg1, fparg0);
        p += 12;
    }
    p = (char *)arg1->ctl;
    func_00478C98(2);
    ((struct Ctl0047F380 *)p)->b = 0;
    p = arg0->base;
    while (p != end) {
        func_00446390(p, arg1, fparg0);
        p += 12;
    }
}
