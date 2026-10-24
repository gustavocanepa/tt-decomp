/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta,index; void *fn; };
struct Color { float x,y,z,w; };
struct Vec { float x; int y; float z; };
struct Item { unsigned int flags; unsigned short id,pad6,count,pada; int padc,pad10; unsigned short *indices; char pad18[0x28]; };
struct Scene { char pad[0x14]; void *model; int count; Item *items; };
struct Link3 { char pad[0xCC]; Scene *scene; };
struct Link2 { int pad; Link3 *next; };
struct Link1 { char pad[0x80]; Link2 *next; };
struct Face { char pad[0x64]; Entry *vt; int pad68; Link1 *next; };
struct Target { Entry *vt; };
struct Owner { char pad[0x108]; int mode; char padf0[0x20]; float pulse; };
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define I(p,o) (*(int *)((char *)(p)+(o)))
extern Color D_00579CA8;
extern Color D_00579C88[2];
extern "C" void func_0017E628(Color *,float) throw();
extern "C" float func_00318728(void *);
extern "C" void func_003782A8(Scene *,int,float,float,float,float);
extern "C" void ModelSet2__render(void *,void *);
extern "C" void func_0046D810(int,void *,int,int,int,int);
extern "C" void func_0046F0F8(int);
extern "C" void func_0046F498(int);
extern "C" void func_004702D8(int,float);
extern "C" void func_00470450(int);
extern "C" void func_00470478(int);
extern "C" void func_00470B48(int);
extern "C" void func_00470B58(float);
extern "C" void func_00470E60(int);
extern "C" void func_00473178(int);
extern "C" Vec *func_00473980(int);
extern "C" void func_00474E90(Vec *,Vec *);
extern "C" void func_004751FC();
extern "C" void func_00477DC0(int);
extern "C" void func_00478C98(int);
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
static inline Target *target(Face *f) {
 Entry *e=(Entry *)((char *)f->vt+0x4E8);
 return ((Target *(*)(void *))e->fn)((char *)f+e->delta);
}
static inline void call(Target *t,int slot) {
 Entry *e=(Entry *)((char *)t->vt+slot);
 ((void (*)(void *))e->fn)((char *)t+e->delta);
}
extern "C" void func_0017E6F8(Owner *self,Face *face) {
 func_00470450(-1);
 func_00470478(1);
 func_00470B48(0);
 func_00470B58(1.0f);
 func_00470E60(3);
 func_0046F498(0);
 Scene *scene=face->next->next->next->scene;
 if (scene) {
  Target *t;
  int i=0;
  void *model=scene->model;
  t=target(face);
  func_00473178(1);func_004751FC();
  char *camera=(char *)t+0xF00;
  call(t,0x228);
  func_00473178(0);func_004751FC();call(t,0x230);
  ModelSet2__render(model,0);
  func_00478C98(15);func_00478C98(4);func_00478C98(2);func_0046F0F8(6);func_004702D8(0x44,1.0f);
  for (;i<scene->count;i++) {
   Item *item=scene->items+i;
   int id=item->id;
   int active;
   if (I(camera,0x40)==i) {
    active=1;
    for (int j=0;j<item->count;j++) {
     int index=item->indices[j];
     Color color=D_00579CA8;
     if(self->mode==1)func_0017E628(&color,self->pulse);
     func_003782A8(scene,index,color.x,color.y,color.z,color.w);
    }
   } else active=0;
   if (item->flags&1) {
   } else {
    Color *c=D_00579C88+active;
    func_003782A8(scene,id,c->x,c->y,c->z,c->w);
   }
  }
  if (self->mode!=2) {
   float length=2.0f*func_00318728(camera);
   float x=F(camera,0x60);
   float width=F(camera,0xCC)/F(t,0xA80);
   float z=F(camera,0x68);
   float angle=F(camera,0x6C);
   Vec *v=func_00473980(3);
   angle-=90.0f;
   v[0].x=x;v[0].y=0;v[0].z=z;
   width*=0.5f;
   float a=(angle-width)*0x1.921fb4p+1f/180.0f;
   float b=(angle+width)*0x1.921fb4p+1f/180.0f;
   float c=func_004A5C50(a);
   v[1].y=0;v[1].x=x+length*c;
   v[1].z=z+length*func_004A5D18(a);
   c=func_004A5C50(b);
   v[2].y=0;v[2].x=x+length*c;
   v[2].z=z+length*func_004A5D18(b);
   func_00477DC0(0x23ffffff);
   func_0046D810(3,v,0,0,0,0);
   if (I(camera,0xBC)) {
    float angles[2]; Vec points[2];
    angles[0]=(F(camera,0xC4)-90.0f)*0x1.921fb4p+1f/180.0f;
    angles[1]=(F(camera,0xC8)-90.0f)*0x1.921fb4p+1f/180.0f;
    for (int k=0;k<2;k++) {
     points[0].x=x;points[0].y=0;points[0].z=z;
     float c=func_004A5C50(angles[k]);
     points[1].y=0;points[1].x=x+length*c;
     points[1].z=z+length*func_004A5D18(angles[k]);
     func_00477DC0(0x50ffffff);
     func_00474E90(points,points+1);
    }
   }
  }
 }
}
