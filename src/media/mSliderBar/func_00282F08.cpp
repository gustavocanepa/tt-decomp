/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slider { char pad[0xDC]; int c0; int c4; char padC8[0x44]; int popup; };
struct Event { char pad[0x20]; int key; };
extern "C" int func_00282C00(Slider *, void *, Event *) throw();
extern "C" int func_00282D00(Slider *, void *, Event *) throw();
extern "C" void func_00282DF8(Slider *, void *) throw();
extern "C" void func_00282E70(Slider *, void *, int) throw();
extern "C" int func_0020B6A0(Slider *, void *, Event *);
extern "C" int func_00282F08(Slider *self, void *arg, Event *ev) {
 if (self->c0) {
  if (ev->key == 0xFF0D) {
   if (self->popup == 0) func_00282DF8(self, arg);
   else func_00282E70(self, arg, 0);
   return 1;
  }
  if (ev->key == 0xFF1B && self->popup) { func_00282E70(self, arg, 1); return 1; }
 }
 if (self->c0 == 0) return func_00282C00(self, arg, ev);
 if (self->c4 && self->popup) return func_00282D00(self, arg, ev);
 return func_0020B6A0(self, arg, ev);
}
