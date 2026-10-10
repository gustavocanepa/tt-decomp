typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);
extern "C" s32 func_0043D2A0(const char *);

extern "C" void func_0043D6E8(Val *self, const char *s) {
    s32 type = 3;
    func_0043D510(self);
    self->type = type;
    self->v = func_0043D2A0(s);
}
