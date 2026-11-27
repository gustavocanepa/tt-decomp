/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    int first;
    void *vtbl;
    char pad[0x1D94 - 8];
    int a, b, c, d;
};
struct Input { char pad[0x458]; int value; };
struct Screen { char pad[0x34]; float width, height; };
extern char D_005AF5D8[];
extern Screen *D_00586EF4;
extern "C" void *func_001DF328(Obj *, Input *);
extern "C" void *func_00104838(char *);
extern "C" int func_001C7768(Obj *self, Input *arg) {
    func_001DF328(self, arg);
    self->vtbl = D_005AF5D8;
    func_00104838((char *)self + 0x1D58);
    self->a = 0;
    self->b = 0;
    self->c = arg->value;
    self->d = 0;
    Screen *screen = D_00586EF4;
    screen->width = 640.0f;
    screen->height = 480.0f;
}
