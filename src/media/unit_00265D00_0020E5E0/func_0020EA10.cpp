/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xAC]; unsigned int low:8; unsigned int f:4; unsigned int rest:20; };
extern "C" void func_0020EA10(Obj *self,int mask,int enabled) {
    if(enabled) self->f |= mask;
    else self->f &= ~mask;
}
