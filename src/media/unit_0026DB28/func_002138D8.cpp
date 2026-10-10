typedef int s32;
typedef float f32;

struct Obj {
    s32 kind;
};

extern "C" s32 func_00213770(Obj *);
extern "C" s32 func_00213B30(Obj *, f32);

extern "C" s32 func_002138D8(Obj *self) {
    switch (self->kind) {
    case 0:
        return func_00213B30(self, 0.0f);
    case 1:
    case 2:
        return func_00213770(self);
    }
    return 0;
}
