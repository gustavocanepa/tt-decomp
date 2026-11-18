/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z,w; };
struct Obj { char pad[0x890]; Vec a[3],b[3],c[3],d; };
extern "C" void func_003808D0(Vec *, float);
extern "C" void func_00380300(Obj *self, float dt) {
 Obj *cur=self;
 for (int i=0; i<3; ++i, cur=(Obj *)((char *)cur+16)) {
  Vec *p=&cur->c[0];
  Vec *q=&cur->b[0];
  func_003808D0(p,dt);
  cur->b[0].w=p->x;
  func_003808D0(&cur->a[0],dt);
  func_003808D0(q,dt);
 }
 func_003808D0(&self->d,dt);
}
