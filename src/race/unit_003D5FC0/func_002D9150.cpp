/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rep { u32 len, cap, ref, selfish; };
struct Str { char *p; };
struct Entry { short delta, pad; void *fn; };
struct Found { char pad0[0x5c]; Entry *entry; };
extern Rep D_005A4C58;
extern "C" void func_0056BAF8();
extern "C" void func_00569F90();
extern "C" Found *func_004475D8(int,Str *);
extern "C" void free(void *) throw();
extern "C" u32 func_004A8368(const char *) throw();
extern "C" int GT4MC__FileGT4GameData__loadInstance(void *,void (*)(),int,char *,void (*)(),Found *);
extern "C" char *strobe__toUpper(Rep *);
extern "C" Str *func_00550E18(Str *,u32,u32,const char *,u32);
extern "C" void func_00447398(int,int);
extern "C" void func_00446A58(int,void *);
static inline void destroy(Str *s) { Rep *r=(Rep *)s->p-1; if(--r->ref==0) free(r); }
extern "C" void func_002D9150(void *owner,int handle,const char *name,int index) {
    Str s;
    Str *ps=&s;
    Rep *r=&D_005A4C58;
    char *d=(char *)(r+1);
    if(r->selfish) d=strobe__toUpper(r);
    else ++r->ref;
    ps->p=d;
    func_00550E18(ps,0,-1,name,func_004A8368(name));
    int result=0;
    Found *f=func_004475D8(handle,&s);
    if(f) { Entry *e=f->entry; result=GT4MC__FileGT4GameData__loadInstance(e->fn,func_0056BAF8,0,(char *)f+e->delta,func_00569F90,f); }
    destroy(&s);
    if(result) {
        func_00447398(result,index);
        func_00446A58(result,owner);
        func_00446A58(result,owner);
    }
}
