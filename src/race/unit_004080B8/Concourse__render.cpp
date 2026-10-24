/* compiler: ee-gcc2.96-nsa-nosib */
struct Entry { int id, flag; float alpha,scale,angle; char pad[0x16c-20]; float x,y,z; };
struct Model { char pad[0x7c]; struct State *state; };
struct State { char pad[20]; void *p; };
struct Inner { int a,b,c; Model *model; int other; };
struct VT { short off, pad; int (*fn)(void *); };
struct Obj { int a; Inner *inner; int count; Entry *entries; VT *vt; };
struct Global { int a,b; }; extern Global D_00769510;
extern "C" {
int func_003C8650(Obj *) throw(); int func_003C82C0(float,float,float) throw();
float func_003C8538(Entry *,float,float) throw();
void func_003CAA28(void *,void *); void *func_0034E420(void *,void *);
void func_003EEC90(void *); void func_003EECA0(void *,void *,int);
void func_003EFF48(void *,int,int,int,float,float); void func_003F0070(void *,int,int,int,int,float,float);
void func_00421C10(int); void func_00468B68(float); void func_00470478(int);
void func_00473178(int); void func_00473050(); void func_004730A8();
void func_00475440(void *); void func_004755EC(float,float,float); void func_00475638(float,float,float); void func_00475758(float);
}
static inline int vcall(Obj *o) { VT *v=o->vt+1; return v->fn((char*)o+v->off); }
extern "C" void Concourse__render(Obj *o,void *car) {
 char buf[16]; float matrix[16]; float pos[4];
 if(func_003C8650(o)) {
  for(int i=0;i<o->count;i++) {
   Entry *e=o->entries+i;
   float *x, *y, *z; z=&e->z; x=&e->x; y=&e->y;
   float scale=e->scale; int flag=e->flag; float angle=e->angle;
   if(func_003C82C0(*x,*y,*z)) {
    func_003CAA28((char*)(o->entries+i)+0x20,car);
    func_00473178(0); func_00473050(); func_004755EC(*x,*y,*z);
    float degrees=angle*180.0f/3.14f; func_00475758(degrees);
    func_003EEC90(buf); func_00473050();
    float *px=&pos[0]; func_0034E420(car,pos); pos[3]=0;
    float *pz=&pos[2];
    float len=*px**px+*pz**pz;
    if(len>=2.25f) {float factor=1.5f; __asm__("rsqrt.s %0,%1,%2":"=f"(factor):"f"(factor),"f"(len)); *px *= factor; *pz *= factor; }
    pos[1]=func_003C8538(o->entries+i,*px,*pz);
    float xx=*px, yy=pos[1], zz=*pz; float *m=matrix; *m=1; matrix[4]=xx; matrix[5]=yy; matrix[6]=zz;
    matrix[12]=matrix[8]=0.0f; matrix[13]=matrix[9]=matrix[1]=0.0f; matrix[2]=0.0f; matrix[10]=1; matrix[14]=0.0f; matrix[11]=matrix[7]=matrix[3]=0.0f; matrix[15]=1;
    func_00473178(1);func_00473050();func_00468B68(.01f);func_00473178(0);
    func_00475758(-angle*180.0f/3.14f);func_00475440(m);func_00475758(degrees);func_00470478(0);
    if(scale!=1)func_00475638(scale,scale,scale);
    func_003EECA0(buf,(void*)o->inner->other,o->inner->b);
    if(vcall(o)) {Entry *p=o->entries+i; int id=p->id; int v=vcall(o); Entry *q=o->entries+i;func_003F0070(buf,id,v,0,0,q->alpha,0);}
    else {Entry *q=o->entries+i;func_003EFF48(buf,q->id,0,0,q->alpha,0);}
    func_00470478(1);func_00473178(1);func_004730A8();func_00473178(0);func_004730A8();
    if(scale!=1)func_00475638(scale,scale,scale);
    func_003EECA0(buf,o->inner->model,o->inner->b);
    if(flag>=0) {D_00769510.b=flag;o->inner->model->state->p=&D_00769510;func_00421C10(0);}
    else o->inner->model->state->p=0;
    if(vcall(o)) {Entry *p=o->entries+i; int id=p->id; int v=vcall(o); Entry *q=o->entries+i;func_003F0070(buf,id,v,0,0,q->alpha,0);}
    else {Entry *q=o->entries+i;func_003EFF48(buf,q->id,0,0,q->alpha,0);}
    if(flag>=0)func_00421C10(1);
    func_004730A8();
   }
  }
 }
}
