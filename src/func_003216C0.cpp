/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" int func_00416E68(void *);
extern char D_005C9AB0[];
struct Vec { float v[3]; };
struct Elem { float a,b,c; Vec v0; float d,e,f; Vec v1,v2,v3,v4,v5,v6; };
struct Cam { void *vt; Elem el[2]; char pad[0x168-4-2*sizeof(Elem)]; unsigned long flags; };
extern "C" int func_003216C0(Cam *self) {
 func_00416E68(self);
 self->vt = D_005C9AB0;
 for(int i=0;i<2;i++) {
  self->el[i].a=1.0f; self->el[i].b=1.0f; self->el[i].c=70.0f;
  func_004F6678(&self->el[i].v0,0,12);
  self->el[i].d=1.0f; self->el[i].e=1.0f; self->el[i].f=1.0f;
  func_004F6678(&self->el[i].v1,0,12);
  func_004F6678(&self->el[i].v2,0,12);
  func_004F6678(&self->el[i].v3,0,12);
  func_004F6678(&self->el[i].v4,0,12);
  func_004F6678(&self->el[i].v5,0,12);
  func_004F6678(&self->el[i].v6,0,12);
 }
 self->flags &= 0xFFFFFFFF00FFFFFFUL;
}
