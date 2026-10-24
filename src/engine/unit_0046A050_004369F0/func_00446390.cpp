#include "types.h"
struct Sub0047F660 {
    char *base;
    s32 count;
};
struct Obj0047F660 {
    int unk0;
    struct Sub0047F660 sub;
};
extern "C" void func_00446448(char *a, void *b, f32 c);

extern "C" void func_00446390(struct Obj0047F660 *arg0, void *arg1, f32 fparg0) {
    struct Sub0047F660 *s;
    char *p;
    char *end;

    s = &arg0->sub;
    char *base = s->base;
    end = base + s->count * 28;
    p = base;
    while (p != end) {
        func_00446448(p, arg1, fparg0);
        p += 28;
    }
}
