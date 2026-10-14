/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { float f0,f4,f8,fc,f10,f14,f18,f1c,f20; int i24,i28; char pad[0x68-0x2c]; int i68; };
extern "C" void func_00104838(char *);
extern "C" void func_0038B818(void *, float, float);
extern "C" int func_0038B758(Obj *self) {
    func_00104838((char *)self+0x2c);
    int minus=-1;
    func_0038B818(self,35.0f,0x1.553f7cp+0f);
    self->f8=2.0f;
    self->fc=0x1.1eb85p-5f;
    self->f10=10.0f;
    self->f1c=8.0f;
    self->f20=4.0f;
    self->i24=2;
    self->i28=1;
    self->f14=0x1.999998p-4f;
    self->f18=1000.0f;
    self->i68=minus;
}
