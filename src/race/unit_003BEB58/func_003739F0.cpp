/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[12]; Node *next; int p10,id; };
struct List { char pad[8]; Node **entries; char gap[12]; Node *head; };
struct Context { char pad[0x60]; List *list; };
struct Texture { char pad[0x20]; unsigned long bits; };
struct Image { char pad[0x18]; Texture *tex; };
struct Resource { char pad[0x28]; Image *image; char gap[8]; unsigned short w,h; };
struct Self { char pad[0x18]; Resource *res; char gap[0x24]; int mode,ready; float pulse; };
struct Target { int id,flags,w,h; };
extern "C" {
void func_00104A48(Target*,int,int);
int func_00104B10(Target*);
void func_00104C88(Target*);
void func_0038E480(void*,float,float,float);
int func_0038F5F8(int,float);
void func_003734F8(void*) throw();
void func_003738C8(Self*,Node*,int,unsigned int,float) throw();
void func_0046F0F8(int);
void func_00470220(int,float);
void func_00470298(int);
void func_004702D8(int,float);
void func_00470450(int);
void func_00470478(int);
void func_00470B48(int);
void func_00470E60(int);
void func_00473178(int);
void func_00473050();
void func_004730A8();
void pglPushAttrib(int);
void func_00473498();
void func_004738A0(float,float,float,float,float,float);
void func_004751FC();
void func_004755EC(float,float,float);
void func_00475638(float,float,float);
void func_00477DC0(unsigned int);
void func_00478C98(int);
}
static inline float minf(float a,float b) { float r; __asm__("min.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
extern "C" void func_003739F0(Self *s,Target *t,Context *ctx,int idx) {
 if(!s->ready) func_003734F8(s);
 Image *im=s->res->image;
 if(im) {
  pglPushAttrib(0x81);
  unsigned long bits=im->tex->bits;
  int iw=((bits>>14)&0x3ff)+1;
  int ih=((bits>>34)&0x3ff)+1;
  int hw=s->res->w, hh=s->res->h;
  if(hw==0 || hh==0) { hw=iw>>1; hh=ih>>1; }
  int w=hw*2, h=hh*2;
  if(t->id==-1) { func_00104A48(t,w,h); t->flags=0; func_00104B10(t); }
  func_00104C88(t);
  func_00470450(-1); func_00470B48(0); func_00470E60(1);
  func_0046F0F8(6); func_0046F0F8(4); func_00478C98(15); func_00478C98(5); func_00470478(0);
  func_004702D8(0x44,0); func_00470220(6,0); func_00470298(0);
  func_00473178(1); func_00473050(); func_004751FC();
  float tw=t->w, th=t->h;
  func_004738A0(0,tw,th,0,-1,1);
  func_00473178(0); func_00473050(); func_004751FC();
  func_004755EC(tw-w*0.5f,th-h*0.5f,0);
  float scale=minf(tw/w,th/h); scale=minf(scale,1);
  func_00475638(scale,scale,1);
  Node *selected=ctx->list->entries[idx];
  if(!s->mode) func_003738C8(s,selected,1,0x80000000,1);
  func_00477DC0(0x80ffffff);
  func_004702D8(0x64,1); func_00470220(6,0.2f);
  func_0038E480(s->res->image,0,0,1);
  func_004702D8(0x44,0); func_00470220(6,0);
  for(Node *n=ctx->list->head;n;n=n->next) if(n->id!=idx) func_003738C8(s,n,0,0x80ffffff,1);
  if(!s->mode) {
   func_0046F0F8(4); func_00470220(6,0.5f); func_00470298(0);
   func_003738C8(s,selected,1,func_0038F5F8(0x80ffffff,s->pulse*0.7f+0.3f),1);
  } else func_003738C8(s,selected,1,0x805ea8f2,1);
  func_00478C98(4); func_004730A8(); func_00473178(1); func_004730A8(); func_00473178(0); func_00473498();
 }
}
