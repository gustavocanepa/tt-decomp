typedef int s32;

struct Obj {
    char pad[4];
    char sign;
    char text[0xAF];
    s32 dirty;
};

extern "C" void func_0037E860(char *, s32);

extern "C" void func_0037E940(Obj *o, s32 value, s32 positive) {
    func_0037E860(o->text, value);
    o->sign = positive ? '+' : ' ';
    o->dirty = 1;
}
