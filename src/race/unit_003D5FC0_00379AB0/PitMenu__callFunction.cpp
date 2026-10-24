/* compiler: ee-gcc2.96-no-strict-aliasing */
#define F(p,t,o) (*(t *)((char *)(p)+(o)))
typedef unsigned int u32;
extern "C" {
void func_00301630(void *,unsigned char,unsigned char,int,int);
int func_00379FA8(const char *) throw();
char *func_0037A020(const char *) throw();
int func_0037A770(void *);
int func_0037A7B8(void *);
char *func_003C8058(void *,int);
char *func_003C8108(void *,int);
char *func_003C8298(void *);
int func_0043D3B8(void *,void *);
void func_0043D510(void *);
void func_0043D738(void *,const char *);
char *strobe__Any__toString(void *);
float func_0043E0B0(void *);
void func_00447CD8(void *);
void func_00447D00(void *,int);
void func_0044C548(const char *);
int func_004A8368(const char *) throw();
int func_005507D8(void *,const char *,u32,u32);
}
extern char D_005F7110[],D_005F7120[],D_005F7130[],D_005F7138[],D_005F7148[],D_005F7150[],D_005F7160[],D_005F7170[],D_005F7180[],D_005F7188[],D_005F7198[];
extern char *D_0058467C;
struct Value { int tag; float val; char pad[8]; Value(){tag=1;} Value(int n){tag=6;val=(float)n;} Value(const Value &v){func_0043D3B8(this,(void *)&v);} ~Value(){func_0043D510(this);} void assign(const char *s){func_0043D738(this,s);} };
static inline bool eq(void *s,const char *t){return func_005507D8(s,t,0,func_004A8368(t))==0;}
static inline void *top(void *s){return F(s,char *,8)-8;}
static inline void number(void *r,int n){F(r,int,0)=6;F(r,float,4)=(float)n;}
extern "C" Value PitMenu__callFunction(char *self,void *name,int count,void *stack){
 if(eq(name,D_005F7110)){
  func_0044C548(strobe__Any__toString(top(stack)));
 }else if(eq(name,D_005F7120)){
  F(self,int,0xe0)=0;
 }else if(eq(name,D_005F7130)){
  int a=func_0037A770(self);
  int b=func_0037A7B8(self);
  int mode=255;
  if(F(self,int,0x100)) mode=F(self,int,0xfc)!=0;
  func_00301630(F(F(self,void *,0xd8),void *,0x18),a<0?255:(a&255),b<0?255:(b&255),F(self,int,0xf8),mode);
  F(self,int,0xdc)=0;
 }else if(eq(name,D_005F7138)){
  int item=func_00379FA8(strobe__Any__toString(top(stack)));
  func_00447CD8(stack); count--;
  int n=(int)func_0043E0B0(top(stack));
  func_00447D00(stack,count);
  Value v;
  if(item==0){
   char *p=self+0x10;
   if(F(self,int,0xe8)){
    if(n!=F(p,int,0x44)) v.assign(func_003C8058(p,n));
    else v.assign(func_003C8298(p));
   }else v.assign(D_0058467C);
  }else if(item==1){
   if(F(self,int,0xe8)){
    char *p=self+0x10;
    if(n==F(self,int,0xa0))v.assign(func_003C8298(p));
    else v.assign(func_003C8108(p,n));
   }else v.assign(D_0058467C);
  }else if(item==2){
   if(F(self,int,0xec))v.assign(func_0037A020(n==1?D_005F7148:D_005F7150));
   else v.assign(D_0058467C);
  }else{
   if(!F(self,int,0x100))v.assign(D_0058467C);
   else v.assign(func_0037A020(n==1?D_005F7160:D_005F7170));
  }
  return v;
 }else if(eq(name,D_005F7180)){
  int item=func_00379FA8(strobe__Any__toString(top(stack)));
  func_00447D00(stack,count);
  int n;
  if(item==0)n=F(self,int,0xe8)?F(self,int,0x54)+1:1;
  else if(item==1)n=F(self,int,0xe8)?F(self,int,0xa0)+1:1;
  else if(item==2)n=F(self,int,0xec)?2:1;
  else n=F(self,int,0x100)?2:1;
  return Value(n);
 }else if(eq(name,D_005F7188)){
  int item=func_00379FA8(strobe__Any__toString(top(stack)));
  func_00447D00(stack,count);
  int n;
  if((u32)item<2)n=F(self+item*4,int,0xf0);
  else if(item==2)n=F(self,int,0xf8)!=0;
  else n=(F(self,int,0x100)&&F(self,int,0xfc))?1:0;
  return Value(n);
 }else if(eq(name,D_005F7198)){
  count--;
  int item=(int)func_0043E0B0(top(stack));
  func_00447CD8(stack);
  int n=(int)func_0043E0B0(top(stack));
  if((u32)item<2)F(self+item*4,int,0xf0)=n;
  else if(item==2)F(self,int,0xf8)=n!=0;
  else F(self,int,0xfc)=n!=0;
 }
 func_00447D00(stack,count);
 return Value();
}
