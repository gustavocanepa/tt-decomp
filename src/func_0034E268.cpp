/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0[0x10]; int flags; char p1[12]; float scale; char p2[0x9C0-0x24]; float c0,c4,c8,cc,d0,d4,d8,dc,e0; int e4; float e8; };
struct Renderer { char pad[0xa2c]; int value; };
struct Vec { float x,y,z; char pad[4]; };
extern "C" void func_0034E690(Vec *,float,float) throw();
extern "C" void func_00390458(Renderer *,Vec *,float,float,float,float,float,float);
extern "C" void func_0034E268(Obj *p,Renderer *r) {
 Vec v;
 if(p->flags&0x400) {
  func_0034E690(&v,p->dc,p->e0);
  float k=p->scale*0.5f;
  r->value=p->e4;
  v.x*=k; v.y*=k; v.z*=k;
  func_00390458(r,&v,p->cc,p->e8,p->d0*k,p->c0,p->c4,p->c8);
 }
}
