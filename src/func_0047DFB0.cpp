struct Result { int words[5]; };
struct Entry { short adjustment; short unused; void (*call)(void*); };
struct Obj { char unknown[116]; int mode; char gap[12]; Result result; char tail[16]; Entry* table; };
struct Temp { char bytes[172]; ~Temp(); };
extern "C" void func_0047EFD8(Result*);
extern "C" void func_0047E910(Temp*);
extern "C" Obj* func_0047DAE8(Temp*,int);
extern "C" void func_0047EE88(Obj*);
extern "C" void func_0047E9C0(Temp*,int);
inline Temp::~Temp() { func_0047E9C0(this,2); }
inline void call_entry(Obj* obj,int index) { Entry* e=obj->table+index; e->call((char*)obj+e->adjustment); }
extern "C" Result func_0047DFB0(int input) {
 Result result;
 func_0047EFD8(&result);
 Temp temp;
 func_0047E910(&temp);
 Obj* obj=func_0047DAE8(&temp,input);
 if(obj) {
  obj->mode=2;
  call_entry(obj,2);
  call_entry(obj,4);
  result=obj->result;
  func_0047EE88(obj);
 }
 return result;
}
