/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slider { char pad0[0xE0]; int c4; int c8; int cc; char padD0[0x28]; int f8; char padFC[0x10]; int popup; };
extern char D_005F03A0[];
extern "C" void func_001EEDE8(void *);
extern "C" void func_001EEB30(int, void *);
extern "C" void func_001EDBE0(void *, int);
extern "C" void func_001E3970(void *, int);
extern "C" void func_001E5440(void *, int);
extern "C" void func_00282DF8(Slider *self, void *arg) {
 int h[4];
 func_001EEDE8(h);
 func_001EEB30(h[0], D_005F03A0);
 func_001EDBE0(h, 2);
 self->popup = 1;
 func_001E3970(arg, 0);
 func_001E5440(arg, self->c4);
 self->f8 = self->cc;
}
