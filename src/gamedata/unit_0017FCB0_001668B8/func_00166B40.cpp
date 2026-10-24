struct VEntry{short delta,index;int(*fn)(void*);};
struct Obj{int m0;VEntry*vt;};
struct Handle{Obj*p;char pad[12];};
extern "C" void func_001EF140(void*,void*);
extern "C" void func_001EEF60(void*,int);
extern "C" int func_001669C8(void*,Obj*,void*);
static inline int valid(Obj*obj){VEntry*e=(VEntry*)((char*)obj->vt+0x1B8);return e->fn((char*)obj+e->delta);}
extern "C" int func_00166B40(void*arg0,void*arg1,void*arg2){Handle buf;func_001EF140(&buf,arg1);
if(buf.p==0){func_001EEF60(&buf,2);return 0;}if(!valid(buf.p)){func_001EEF60(&buf,2);return 0;}int r=func_001669C8(arg0,buf.p,arg2);func_001EEF60(&buf,2);return r;}
