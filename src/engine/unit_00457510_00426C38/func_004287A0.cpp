/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V2 {
 float x,y;
 V2(){}
 V2(float a,float b):x(a),y(b){}
};
struct V3 { float x,y,z; };
struct Obj { char pad0[0x394]; V2 pos; char pad398[0x84]; int index; V2 normal; V3 *p428; };
extern "C" void func_00426A60(Obj *) throw();
extern "C" void func_004287A0(Obj *self) {
 V2 *normal=&self->normal;
 V3 *p3=self->p428;
 V2 p;
 p.x=p3->x;
 p.y=-p3->z;
 float ny=normal->y, nx=normal->x;
 V2 target=*(V2 *)(self->index*0x44+(char *)self+0x1C);
 float tx=target.x, px=p.x, ty=target.y, py=p.y;
 V2 d(tx-px,ty-py);
 if(d.x*ny-d.y*nx>0.0f) {
  float len=nx*nx+ny*ny;
  float t;
  if(len!=0.0f) t=(d.x*nx+d.y*ny)/len; else t=1.0f;
  float dx=t*self->normal.x+px-tx;
  float dy=t*self->normal.y+py-ty;
  self->pos.x+=dx;
  self->pos.y+=dy;
  V2 delta(dx,dy);
  func_00426A60(self);
 }
}
