typedef int s32;
struct Base {
    char p[0xC];
    Base(s32 a) __asm__("func_0050EFD8");
};
struct Obj : Base {
    const s32 f0C;
    s32 f10;
    Obj(s32 a, s32 b, s32 c) __asm__("func_00108818");
};
Obj::Obj(s32 a, s32 b, s32 c) : Base(a), f0C(b) {
    f10 = c;
}
