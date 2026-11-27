/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xAC]; unsigned int low:4; unsigned int f:4; unsigned int rest:24; };
extern "C" void func_0020E9A8(Obj *self,int mask,int enabled) {
    if(enabled) self->f |= mask;
    else self->f &= ~mask;
}
