extern "C" void*func_004A4690(int,int);
extern "C" void free(void*);
struct VEntry{short delta,index;void*fn;};
struct File{VEntry*vt;};struct Owner{char pad[16];File*file;};
struct Storage{int m0;VEntry*vt;};
static inline int count(File*f){VEntry*e=(VEntry*)((char*)f->vt+0x10);return ((int(*)(void*))e->fn)((char*)f+e->delta);}
static inline void serialize(File*f,void*p){VEntry*e=(VEntry*)((char*)f->vt+0x28);((int(*)(void*,void*))e->fn)((char*)f+e->delta,p);}
static inline int func_005AE268(Storage*s,int key,void*p,int n){VEntry*e=(VEntry*)((char*)s->vt+0x1E8);return ((int(*)(void*,int,void*,int))e->fn)((char*)s+e->delta,key,p,n);}
struct Buffer{void*p;int size;};
extern "C" int func_00166BE0(Owner*self,Storage*storage,int key){int n=(count(self->file)+63)&~63;Buffer buf;buf.p=0;buf.size=n;buf.p=func_004A4690(64,n);Buffer*pb=&buf;serialize(self->file,buf.p);int result=func_005AE268(storage,key,buf.p,n);free(buf.p);return result>0;}
