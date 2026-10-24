struct Obj { char pad[0x110]; int count; };
extern "C" void func_001B3090(Obj*);
extern "C" void func_001B3048(Obj* self) {
 --self->count;
 if(self->count <= 0) {
  if(self->count < 0) self->count = 0;
  else func_001B3090(self);
 }
}
