/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slider { char pad[0xE0]; int c4; char padC8[0x34]; int fc,f100,f104,f108,popup; };
extern "C" void func_0020B408(Slider *, void *);
extern "C" void func_001E5440(void *, int);
extern "C" void func_00282850(Slider *self, void *arg) {
 self->f100 = 0;
 self->fc = 0;
 self->c4 = 0;
 self->popup = 0;
 func_0020B408(self, arg);
 func_001E5440(arg, 0);
}
