typedef float f32;

extern "C" f32 func_0041E068(void *self, int which);
extern "C" void func_00425980(void *self, f32 value);

extern "C" void func_0041E318(void *self, int which, int negate) {
    if (!which)
        return;
    f32 v = func_0041E068(self, which);
    if (v != 0.0f)
        func_00425980(self, negate ? -v : v);
}
