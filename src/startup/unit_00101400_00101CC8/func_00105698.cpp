typedef int s32;

struct Ent {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
};

extern struct Ent D_00579670[8];

extern "C" s32 func_00105698(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    struct Ent *e = D_00579670;
    for (i = 0; i < 10; i++, e++) {
        if (e->a == arg0 && e->b == arg1 && e->c == arg2) {
            return e->id;
        }
    }
    return 0;
}
