struct Model { char pad[0x2e]; unsigned short n; };
struct Elem { int x; char *loops; char *motions; int z; };
struct Data { char pad[16]; Elem *elems; };
struct Self { Model *model; Data *data; unsigned short *list; };
struct Context { char pad[28]; float x,y,z; void *buffer; int unused; };
struct Entry { int x; int id; };
extern "C" {
void func_003EFC00(void*,void*,const unsigned short*) throw();
int GT4_Motion__MotionSetPlayer__getSkinningBufferSize(Self*);
void *func_004A4690(int,int);
void func_004A45D0(void*) throw();
void func_003F1EB0(Context*,Model*,void*,unsigned short*);
void func_003F1EE8(Context*,int);
float func_003F4AB8(void*,float);
float func_003F1AF0(void*,float);
int func_003F1E70(Context*,unsigned short);
float func_003F39A0(Elem*,int,float,Context*);
void func_003F39E8(Elem*,int,float,float,Context*);
void ModelSet2__begin(Model*,void*);
void ModelSet2__end(Model*);
Entry *ModelSet2__searchModelName(Model*,const char*,int*);
void ModelSet2___render(Model*,int,void*);
void func_00473050();
void func_004751FC();
void func_004755EC(float,float,float);
void func_00475908(void*,int);
void func_004730A8();
extern char D_005F9240[];
void func_003EFC98(Self *self,int index,int a,int b,void *buffer,void *render,float *out,float time,float blend) {
 Context ctx;
 int count;
 int bones;
 if (self->model) {
  if (!self->data) { func_003EFC00(self->model,render,self->list); return; }
  void *work=buffer;
  bones=self->model->n;
  if (!work) work=func_004A4690(64,GT4_Motion__MotionSetPlayer__getSkinningBufferSize(self));
  func_003F1EB0(&ctx,self->model,render,self->list);
  ctx.buffer=work;
  int mode;
  if(a>=0) { b=a; mode=1; }
  else { mode=0; if(b<0) { func_003F1EE8(&ctx,2); return; } }
  Elem *elem=self->data->elems+index;
  if(mode) time=func_003F4AB8(elem->loops+b*32,time);
  else time=func_003F1AF0(elem->motions+b*32,time);
  if(out) *out=time;
  ModelSet2__begin(self->model,0);
  if(mode) func_003F39A0(elem,b,time,&ctx);
  else func_003F39E8(elem,b,time,blend,&ctx);
  if(work) {
   Entry *entries=ModelSet2__searchModelName(self->model,D_005F9240,&count);
   if(entries) {
    int i=0;
    func_00473050(); func_004751FC();
    func_004755EC(ctx.x,ctx.y,ctx.z);
    func_00475908(work,bones);
    for(;i<count;i++) {
     int id=entries->id; entries++;
     if(func_003F1E70(&ctx,(unsigned short)id)) ModelSet2___render(self->model,id,render);
    }
    func_004730A8();
   }
  }
  ModelSet2__end(self->model);
  if(!buffer) func_004A45D0(work);
  func_003F1EE8(&ctx,2);
 }
}
}
