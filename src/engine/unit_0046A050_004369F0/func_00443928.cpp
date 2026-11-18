/* compiler: ee-gcc2.96-stl */
extern "C" void free(void *) throw();
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>
typedef unsigned int u32;
struct Val;
extern "C" int func_0043D3B8(Val *, const Val *) throw();
extern "C" void func_0043D510(Val *);
extern "C" void func_0043D6E8(Val *, const char *) throw();
extern "C" void func_0043D738(Val *, int);
extern "C" char *strobe__Any__toString(Val *) throw();
extern "C" float func_0043E0B0(Val *) throw();
struct Stack { int a,b; Val *end; };
extern "C" void func_00447CD8(Stack *);
extern "C" void func_00447D00(Stack *, int);
extern "C" void free(void *) throw();
extern "C" void func_004A6448(const char *, ...);
extern "C" int func_004A8368(const char *) throw();
extern "C" void *func_004F6574(void *, const void *, u32) throw();
extern "C" void *func_004F8588(void *, const void *, int) throw();
extern char D_00601BF0[], D_00601BF8[];
struct Val {
 int type, value;
 Val():type(1) {}
 Val(const Val &v) { func_0043D3B8(this, &v); }
 ~Val() { func_0043D510(this); }
};
typedef vector<char> Vec;
template <> void Vec::insert(char *, unsigned int, const char &) __asm__("func_00569BD0");
extern "C" Val func_00443928(Val *self, int count, Stack *stack) {
 if(count==2) {
   Val result;
   const char *str=strobe__Any__toString(self);
   int start=(int)func_0043E0B0(stack->end-1);
   func_00447CD8(stack);
   int len=(int)func_0043E0B0(stack->end-1);
   func_00447CD8(stack);
   if(start<0) return result;
   int total=func_004A8368(str);
   if(start>total) {func_0043D738(&result,(int)D_00601BF0); return result;}
   if(start+len>=total) {func_0043D6E8(&result,str+start); return result;}
   char buf[256];
   Vec v;
   char *p=buf;
   if(len>=255) {v.resize(len+1); p=v.begin();}
   func_004F8588(p,str+start,len);
   p[len]=0;
   func_0043D6E8(&result,p);
   return result;
 }
 func_004A6448(D_00601BF8);
 func_00447D00(stack,count);
 return Val();
}
