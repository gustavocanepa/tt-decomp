typedef int s32;
struct VEntry { short delta, index; void (*fn)(void *, int); };
struct Obj { void *vtable; };
struct CarGarage { char pad[0x10]; s32 has; void *obj; };
extern "C" void func_00411E38(void *, int);
extern "C" void func_002A7958(void *, int);
extern "C" void func_004A45D0(void *);
extern "C" char D_005A63F8[];
extern "C" void mCarGarage__structor_5(CarGarage *self, int flags) {
  *(char **)((char *)self + 4)=D_005A63F8;
  if (self->has != 0) {
    Obj *obj=(Obj *)self->obj;
    if (obj != 0) {
      self->obj=0;
      self->has=0;
      VEntry *e=(VEntry *)((char *)obj->vtable+8);
      e->fn((char *)obj+e->delta,3);
    }
  }
  func_00411E38((char *)self+0x18,2);
  func_002A7958(self,0);
  if (flags & 1) return func_004A45D0(self);
}
