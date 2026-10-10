typedef int s32;

struct Id {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" void func_00424318(Id *id);

extern "C" Id func_00424358(void) {
    Id t;
    t.b = -1;
    t.c = 0;
    t.a = 0;
    func_00424318(&t);
    return t;
}
