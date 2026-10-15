/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned int u32;
struct Word { u32 word; } __attribute__((packed));
struct Header { char pad[0x2c]; Word value; };
struct Buf { char pad[8]; char *data; };
struct Obj { char pad[4]; void *list; char pad2[0x50-8]; u32 size; int start,state,stride; char pad3[4]; int count; char pad4[12]; int empty; void *vt; u32 value; int index; };
extern char D_005DAB00[];
extern "C" void *func_00488648(Obj *,int,void *) throw();
extern "C" int func_004872A8(Header **) throw();
extern "C" Buf *func_00487850(void *,u32) throw();
extern "C" void func_00487968(void *,Buf *) throw();
extern "C" int func_0048BAC8(Obj *,int);
extern "C" void func_0048BB58(Obj *,int,int);
extern "C" void func_0048B8B0(Obj *p,int a1,void *a2,Header **arg3) {
 func_00488648(p,a1,a2);
 p->vt=D_005DAB00;
 p->value=(*arg3)->value.word;
 int n=func_004872A8(arg3);
 p->index=n;
 if(n>=0) { p->state=1; p->start+=p->stride*n; }
 int f=func_0048BAC8(p,1);
 if(f>0) func_0048BB58(p,1,f&0xf7ffffff);
 int block=0;
 p->empty=0;
 u32 off=0;
 int i=0;
 while(i<p->count) {
  Buf *b=func_00487850(p->list,p->start+block);
  if(!b) { i+=p->size>>2; } else {
   while(i<p->count && off<p->size) {
    u32 v=((Word *)(b->data+off))->word;
    off+=4;
    if(!(v&0x0fffffff)) p->empty++;
    i++;
   }
   func_00487968(p->list,b);
  }
  off=0;
  block++;
 }
}
