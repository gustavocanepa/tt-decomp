/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int a; int *begin,*end,*cap; };
struct Self { int a,b; Vec names; void *handle; };
extern "C" int func_002C0F28(void *);
extern "C" void *func_002A2CC0(void *);
extern "C" void *func_002BB3A8(void *);
extern "C" void func_002A7A30(void *);
extern "C" void *func_002ACDB0(void *,void *,int);
extern "C" void func_002A5EE8(void *,void *,void *);
extern "C" int func_002A2810(void *,void *);
extern "C" void func_002A2BE8(void *,void *);
extern "C" void func_002A2770(void *,int);
extern "C" void *func_002A49E8(void *,void *,void *);
extern "C" void func_002BC0E0(void *,int);
extern "C" void func_002A75A8(void *,int);
extern "C" void func_002BAF68(void *,void *,void *);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void func_002C10F0(void *);
extern "C" void func_002C1148(void *);
extern "C" void func_002B1C70(void *,void *) throw();
static inline void *get(void **p) { int bad=0; if(*p==0 || func_002C0F28(*p)==0) bad=1; void *v=0; if(!bad)v=*p; return v; }
static inline void assign(void **dst,void **src) { if(dst!=src) { void *p=*src; if(p)func_002C0FE8(p); if(*dst)func_002C1050(*dst); *dst=p; } }
extern "C" void mModuleDefine__execute(Self *self,void *thread) {
 void **h=&self->handle;
 if(get(h)==0) {
  Vec *names=&self->names;
  void *module[4];
  func_002A2CC0(module);
  if((unsigned)(names->end-names->begin)<2) {
   void *context=func_002BB3A8(thread);
   void *value[4];
   void *symbol[4];
   func_002A7A30(value);
   func_002ACDB0(symbol,names,0);
   func_002A5EE8(context,value,symbol);
   if(func_002A2810(module,value)==0) {
    void *symbol2[4];
    func_002ACDB0(symbol2,names,0);
    func_002A2BE8(symbol,symbol2);
    assign(module,symbol);
    func_002A2770(symbol,2);
    func_002A49E8(symbol,context,module);
    func_002BC0E0(symbol,2);
   }
   func_002A75A8(value,2);
  } else {
   void *result[4];
   func_002BAF68(result,thread,names);
   assign(module,result);
   func_002A2770(result,2);
  }
  void *p=module[0];
  if(p)func_002C10F0(p);
  if(*h)func_002C1148(*h);
  *h=p;
  func_002A2770(module,2);
 }
 func_002B1C70(thread,get(h));
}
