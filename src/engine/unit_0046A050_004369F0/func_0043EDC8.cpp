/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val { int type; int value; bool isString() const {return (unsigned)(type-3)<2;} };
extern "C" Val *func_0043D3B8(Val *,const Val *) throw();
extern "C" void func_0043D510(Val *) throw();
extern "C" const char *strobe__Any__toString(Val *) throw();
extern "C" int func_004A8268(const char *,const char *) throw();
extern "C" bool func_0043EEA0(const Val *,const Val *);
static inline bool isOne(int x) { return x == 1; }
extern "C" bool func_0043EDC8(const Val *a,const Val *b) {
 int at=a->type;
 if ((unsigned)(at-3)<2 || b->isString()) {
  Val ta,tb;
  func_0043D3B8(&ta,a);
  func_0043D3B8(&tb,b);
  int r=func_004A8268(strobe__Any__toString(&ta),strobe__Any__toString(&tb))==0;
  func_0043D510(&tb);
  func_0043D510(&ta);
  return r;
 }
 int bt=b->type;
 if ((isOne(at) && isOne(bt)) || (at==0 && bt==0)) return 1;
 return func_0043EEA0(a,b);
}
