struct Obj { char pad[0x1044]; float value; };
extern "C" void func_00320CE0(void *, float);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_004752F8(void *);
extern "C" void func_00475638(float, float, float);
extern "C" void func_002CA468(Obj *self, float value) {
    float matrix[16];
    if (self->value != 0.0f) {
        func_00473050();
        func_004751FC();
        func_00320CE0(self, value);
        func_004752F8(matrix);
        func_004730A8();
        float scale = matrix[5] / matrix[0];
        func_00475638(scale, 1.0f / scale, 1.0f);
    }
    func_00320CE0(self, value);
}
