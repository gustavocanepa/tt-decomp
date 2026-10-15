typedef int s32;

struct Pair;
struct Rec;

extern "C" void func_004C09A0(struct Pair *base, const struct Rec *r);
extern "C" void func_004F6678(void *dst, s32 c, s32 n);

extern char D_007A5F60[];
extern char D_00598820[];
extern char D_00598B68[];

extern "C" void func_004C0918(s32 arg0) {
    struct Pair *base = (struct Pair *)D_007A5F60;
    func_004F6678(base, 0, 0x400);
    func_004C09A0(base, (const struct Rec *)D_00598820);
    if (arg0 == 1) {
        return;
    }
    if (arg0 == 2) {
        return func_004C09A0(base, (const struct Rec *)D_00598B68);
    }
}
