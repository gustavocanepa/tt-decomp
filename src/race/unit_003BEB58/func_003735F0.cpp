/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[12]; Node *next; int p10,id; };
struct List { char pad[8]; Node **entries; char gap[12]; Node *head; };
struct Context { char pad[0x60]; List *list; };
struct Resource { char pad[0x28]; void *p28; };
struct Self { unsigned char active,fx,fy,p3; short x,y; int p8; float alpha; char pad10[8]; Resource *res; char pad1c[0x18]; float sx,sy; short w,h; int mode,ready; float pulse; };
extern "C" {
void func_0038E480(void*,float,float,float);
float func_0038F448(int,float,float);
int func_0038F5F8(int,float);
void func_003734F8(void*) throw();
void func_003738C8(Self*,Node*,int,int,float);
void func_0046F0F8(int);
void func_00470220(int,float);
void func_00470298(int);
void func_004702D8(int,float);
void func_00473050();
void func_004730A8();
void func_004755EC(float,float,float);
void func_00475638(float,float,float);
void func_00477DC0(int);
void func_00478C98(int);
}
extern "C" void func_003735F0(Self *s,void *ctx,int idx) {
 if(s->active) {
  if(!s->ready) func_003734F8(s);
  func_00473050();
  float w=(float)s->w*s->sx;
  float h=(float)s->h*s->sy;
  float x=func_0038F448(s->fx,(float)s->x,w)+w*0.5f;
  float y=func_0038F448(s->fy,(float)s->y,h)+h*0.5f;
  func_004755EC(x,y,0.0f);
  func_00475638(s->sx,s->sy,1.0f);
  List *l=((Context*)ctx)->list;
  Node *selected=l->entries[idx];
  func_0046F0F8(6);
  func_004702D8(0x44,0.0f);
  if(!s->mode) func_003738C8(s,selected,1,func_0038F5F8(0x80000000,s->alpha),1.0f);
  func_00477DC0(func_0038F5F8(0x80ffffff,s->alpha));
  func_0038E480(s->res->p28,0.0f,0.0f,1.0f);
  List *all=((Context*)ctx)->list;
  int color=func_0038F5F8(0x80ffffff,s->alpha);
  Node *n=all->head;
  for(;n;n=n->next) {
   if(n->id!=idx) func_003738C8(s,n,0,color,1.0f);
  }
  if(selected) {
   if(!s->mode) {
    func_0046F0F8(4);
    func_00470220(6,0.5f);
    func_00470298(0);
    float pulse=s->pulse;
    func_003738C8(s,selected,1,func_0038F5F8(0x80ffffff,s->alpha*pulse*0x1.666666p-1f+0x1.333332p-2f),1.0f);
    func_00478C98(4);
   } else func_003738C8(s,selected,1,func_0038F5F8(0x805ea8f2,s->alpha),1.0f);
  }
  func_004730A8();
 }
}
