struct Obj {
    char pad[0xEC0];
    float unkEC0;
    float unkEC4;
};

extern "C" void func_0046D278(float, float, float, float, float, float);
extern "C" void func_0046D0E0(float, float);

extern "C" void func_0034DBB8(Obj *self) {
    func_0046D278(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    func_0046D0E0(self->unkEC0, self->unkEC4);
}
