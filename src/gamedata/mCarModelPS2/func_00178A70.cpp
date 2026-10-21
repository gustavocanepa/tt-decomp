/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Q {
    s32 type;
    char rest[196];
};

struct Obj {
    char pad0[0x160];
    s32 f158;
};

extern "C" s32 func_00178930(Obj *, Q *, s32) throw();
extern "C" void func_00178CE0(Obj *, Q *);
extern "C" void func_00179188(Obj *);

extern "C" void func_00178A70(Obj *self) {
    Q a;
    Q b;
    while (self->f158 != 0) {
        func_00178930(self, &a, 1);
        if (a.type != 0) {
            func_00179188(self);
            if (func_00178930(self, &b, 0) != 0 && b.type == 2) {
                a = b;
            }
            if (a.type == 1) break;
            func_00178CE0(self, &a);
        }
    }
    func_00179188(self);
}
