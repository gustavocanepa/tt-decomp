/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { float x,y,z; };
struct State { float x,y,z; State():x(0),y(1),z(0){} };
struct VEv { short d,p; Vec3 (*f)(void *,float); };
struct VEi { short d,p; Vec3 (*f)(void *,float,int); };
struct Obj { char *vt; };
struct Item { float x,y,z,dx,dy,dz; };
struct Data { char pad[0x38]; int count; Item *items; };
struct Effect { void *vt; float alpha; };
struct Render { char pad[0x14]; Effect *effect; };
struct Model { char pad[0x7c]; Render *render; };
extern char D_005D9A90[];
extern float D_00769D08[4],D_00769D18,D_00769D1C;
extern "C" {
Data *func_0041AAE0(void *) throw();
void func_0041C308(void *,float,float) throw();
void func_0041C370(void *) throw();
void ModelSet2__begin(Model *,Render *);
void ModelSet2__end(Model *);
void ModelSet2___render(Model *,int,Render *);
void func_00422818(Effect *,int);
void func_0041EAC8(Obj *,float);
void func_0041EB10(Obj *,float);
void func_00473050();
void func_004730A8();
void func_00473EF0(float,float,float,float);
void func_00473F10(float,float,float,float);
void func_004755EC(float,float,float);
void func_00475638(float,float,float);
void func_00475730(float);
void func_00475758(float);
void func_00475780(float);
float func_004A5B78(float,float);
float func_004EE530(float);
}
inline Vec3 vcall(Obj *o,int off,float t) {
 VEv *e=(VEv *)(o->vt+off); return e->f((char *)o+e->d,t);
}
inline Vec3 vcalli(Obj *o,float t,int i) {
 VEi *e=(VEi *)(o->vt+0xE0); return e->f((char *)o+e->d,t,i);
}
extern "C" void func_0041CA50(void *self,Obj *obj,int flag,Model *model,float t) {
 Data *data=func_0041AAE0(self);
 if(data && obj) {
  int any;
  if(model) {
   any = 0;
   State states[4];
   for(int i=0;i<4;i++) {
    Vec3 result=vcalli(obj,t,i);
    Vec3 tmp=result;
    *(Vec3 *)&states[i]=tmp;
    if(states[i].x>0.0f) any=1;
   }
   if(any) {
    Render *render=model->render;
    Effect effect;
    effect.vt=D_005D9A90;
    render->effect=&effect;
    func_00473050();
    if(flag) {
     Vec3 v;
     v=vcall(obj,0x40,t);
     float *px=&v.x,*py=&v.y,*pz=&v.z;
     func_004755EC(*px,*py,*pz);
     v=vcall(obj,0x38,t);
     func_00475758(*py);
     func_00475730(*px);
     func_00475780(*pz);
    } else {
     func_0041EAC8(obj,t);
     func_0041EB10(obj,t);
    }
    if(flag) func_0041C308(self,0.005f,0.02f);
    ModelSet2__begin(model,render);
    func_00473EF0(D_00769D08[0],D_00769D08[1],D_00769D08[2],D_00769D08[3]);
    func_00473F10(0.0f,0.0f,0.0f,0.0f);
    for(int i=0;i<data->count;i++) {
     Vec3 v=*(Vec3 *)&states[i&3];
     float alpha=v.x;
     if(!(alpha<=0.0f)) {
      Item *item=&data->items[i];
      func_00473050();
      func_004755EC(item->x,flag?0.0f:item->y,item->z);
      float yaw=func_004A5B78(item->dx,item->dz)*180.0f/0x1.921fb4p1f;
      float pitch=(0x1.921fb4p0f-func_004EE530(item->dy))*180.0f/0x1.921fb4p1f-90.0f;
      func_00475758(yaw);
      float scale;
      if(!flag) {
       func_00475730(pitch);
       func_00475780(v.z);
      }
      scale=flag ? D_00769D1C : D_00769D18;
      scale*=v.y;
      func_00475638(scale,scale,scale);
      effect.alpha=alpha;
      ModelSet2___render(model,flag!=0,render);
      func_004730A8();
     }
    }
    ModelSet2__end(model);
    if(flag) func_0041C370(self);
    func_004730A8();
    model->render->effect=0;
    effect.vt=D_005D9A90;
    func_00422818(&effect,0);
   }
  }
 }
}
