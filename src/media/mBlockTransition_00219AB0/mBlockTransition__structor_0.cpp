/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int f0; void *vt; char pad8[0x18]; int f20; float f24,f28,f2C; int n30,n34,n38; };
extern char D_005B4A58[];
extern "C" void *mTransition__structor_0(Obj *);
extern "C" int func_005357E8(int *);
extern "C" int func_0021A2A0(Obj *);
extern "C" int mBlockTransition__structor_0(Obj *self,int x,int y) {
    mTransition__structor_0(self);
    self->vt=D_005B4A58;
    func_005357E8(&self->f20);
    self->f24=0.125f;
    self->f28=2.0f;
    self->n30=x;
    self->n34=y;
    self->f2C=0x1.11111p-3f;
    self->n38=0;
    return func_0021A2A0(self);
}
