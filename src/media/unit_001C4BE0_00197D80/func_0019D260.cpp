/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Loads data through func_0019CEE0 into a local buffer while reporting progress (0, then 1), hands
   the data to the sink's slot-6 method on success and frees the buffer either way. The callee
   returns a one-word Result, as in its sibling func_001CCC98: the test then reads $v0. */
struct PEntry { short delta,index; void (*fn)(void*,float); };
struct PTable { char pad[0x10]; PEntry e; };
struct Progress { PTable *vt;int arg;char pad[8]; };
struct Result { int value; };
static inline int status(const Result *const x) { return x->value; }
struct Entry { short delta,index; int (*fn)(void*,void*); };
struct Sink { Entry *vt; };
struct Buf { int unk0; void *data; int size; int cap; int pad[4]; };
extern PTable D_005AC7A0,D_005A7A38;
extern "C" Result func_0019CEE0(void*,void*,Buf*,int);
extern "C" void func_004A45D0(void*);
static inline void progress(Progress *p,float f) { PEntry *e=&p->vt->e;e->fn((char*)p+e->delta,f); }
static inline void put(Sink *o,void *data) { Entry *e=o->vt+6;e->fn((char*)o+e->delta,data); }
extern "C" int func_0019D260(void *self,void *src,int unused,int arg,Sink *sink) {
 Progress p;Result result;Buf buf;
 p.vt=&D_005AC7A0;p.arg=arg;
 PTable *fin=&D_005A7A38;
 progress(&p,0.0f);
 buf.data=0;buf.size=0;buf.cap=0;
 result=func_0019CEE0(self,src,&buf,arg);
 int r=status(&result);
 if(r){int v=result.value;if(buf.data)func_004A45D0(buf.data);p.vt=fin;return v;}
 put(sink,buf.data);
 if(buf.data)func_004A45D0(buf.data);
 progress(&p,1.0f);
 p.vt=fin;return 0;
}
