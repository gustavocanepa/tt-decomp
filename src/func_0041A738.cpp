struct V{short adjust,pad;float(*fn)(void*,int);};struct O{V*table;};
extern "C" void func_0041A808(void*);
extern "C" void func_0041AA80(void*,int,float,float,float);
static inline V& entry(O*p,int i){return p->table[i];}
static inline float query(O*p,int slot,int i){V&e=entry(p,slot);return e.fn((char*)p+e.adjust,i);}
extern "C" void func_0041A738(void*p,O*o){int i=0;func_0041A808(p);do{float x=query(o,11,i),y=query(o,12,i),z=query(o,13,i);func_0041AA80(p,i,x,y,z);++i;}while(i<4);}
