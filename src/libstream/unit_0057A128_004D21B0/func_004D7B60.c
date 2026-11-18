/* compiler: ee-gcc2.9-991111 */
struct S { char pad[16]; int p10; int p14; int flags; int p1c; char pad20[16]; int p30; int p34; };
extern void *func_004D9DF8(void);
extern int func_004D77E8(int,int,int,int*,int,int);
extern int func_004D7978(int,int,int*,int);
extern int func_004D7A48(int,int,int,int*);
extern int func_004D8500(int,int,int,int,int*);
extern void func_004D9D80(int);
extern void func_004D9E00(void*);
extern void func_004D9E90(int,int);
extern void func_004D9EA0(int,void*);
void * __attribute__((register_precision(s0, 128))) func_004D7B60(struct S *s,int n,int size,int a3,int *out,int *err) {
 int base=s->p30;
 int ctx=s->p34;
 int p;
 void *handle=func_004D9DF8();
 int flag;
 if(!handle) { *err=0x81050069; return 0; }
 {
  int type=s->flags & 255;
  if(type==1 || (flag=1,type!=0)) flag=0;
  if(s->flags & 0x1000) flag^=1;
  if(n>=0) {
   p=func_004D77E8(base,ctx,n,err,size,flag);
   if(!p) {
    func_004D9E00(handle);
    return 0;
   }
  } else p=s->p10;
  if(s->flags & 0x6000) {
   int r=-1;
   if(s->flags & 0x2000) r=func_004D7A48(p,size,0,err);
   if(s->flags & 0x4000) r=func_004D7A48(p,size,1,err);
   if(r<=0) {
    if(n>=0) func_004D9D80(p);
    func_004D9E00(handle);
    return 0;
   }
   size=r;
  }
  if(s->flags & 0x1000) {
   flag=func_004D7978(p,size,err,flag^1);
   if(n>=0) func_004D9D80(p);
   if(!flag) {
    func_004D9E00(handle);
    return 0;
   }
   p=flag;
  }
  *out=func_004D8500(p,a3,s->flags & 255,s->p1c,err);
  if(!*out) {
   if(n>=0) func_004D9D80(p);
   func_004D9E00(handle);
   return 0;
  }
  func_004D9E90(p,a3);
  func_004D9EA0(a3,handle);
  if(n>=0) func_004D9D80(p);
  return handle;
 }
}
