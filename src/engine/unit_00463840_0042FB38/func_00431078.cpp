struct Obj {
    char pad[0x34];
    float unk34;
    float unk38;
};

extern "C" void func_00431190(Obj *);
extern "C" void func_00430DE8(Obj *, float);

extern "C" void func_00431078(Obj *self) {
    func_00431190(self);
    func_00430DE8(self, 0.0f);
    self->unk34 = 0.0f;
    self->unk38 = 0.0f;
}
