struct Race { char pad[0xD94]; int visual; };
struct Root { char pad[0x84]; Race *race; };
struct Self { Root *root; char pad[0x10]; int active; };
extern "C" void func_002CFA98(void *, float) throw();
extern "C" void func_0042D500(void);
extern "C" void func_002D0250(Self *self) {
    if (self->root->race->visual == 0) func_0042D500();
    self->active = 0;
    func_002CFA98(self, 1.0f);
}
