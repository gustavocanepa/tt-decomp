/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00767128[];
extern "C" void func_004A4930(void*);
extern "C" void func_004A4970(void*);
extern "C" char *func_002BD298(void*,unsigned);
extern "C" void *func_002BD730();
struct Guard{void *p;Guard(void*x):p(x){func_004A4930(p);}~Guard(){func_004A4970(p);}};
struct Obj{char *vt;};
extern Obj *D_00767124;
struct CountEntry{short delta,index;unsigned (*fn)(void*);};
struct ItemEntry{short delta,index;void *(*fn)(void*,unsigned);};
static inline unsigned count(Obj*p){CountEntry *e=(CountEntry*)(p->vt+0x18);return e->fn((char*)p+e->delta);}
static inline void *item(Obj*p,unsigned i){ItemEntry*e=(ItemEntry*)(p->vt+0x10);return e->fn((char*)p+e->delta,i);}
extern "C" char *func_002BD840(unsigned size){
Guard lock(D_00767128);
unsigned rounded=(size+3)&~3U;
unsigned index=(rounded>>2)-1;
void *p;
if(index<count(D_00767124)) {
p=item(D_00767124,index);
return func_002BD298(p,rounded);
}
p=func_002BD730();
return func_002BD298(p,rounded);
}
