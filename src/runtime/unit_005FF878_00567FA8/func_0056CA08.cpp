/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta,index; void (*fn)(void *,int); };
struct Obj {char pad[0x54]; char *str; int p58; Entry *vt;};
struct Link {Obj *ptr; Link *prev,*next;};
struct Self { Obj base; char pad[0x14]; Link a,b;};
struct Rep { unsigned len,cap,ref,flags; };
extern char D_005D9F38[],D_005D9E78[];
extern "C" void free(void *) throw();
extern "C" void func_0050E1A8(void *) throw();
static inline void drop(Link *h) {
 if(h->prev==h->next) {
  Obj *o=h->ptr;
  if(o) {Entry *e=o->vt+1;e->fn((char *)o+e->delta,3);}
 }else {h->next->prev=h->prev;h->prev->next=h->next;}
}
extern "C" void func_0056CA08(Self *s,int flags) {
 s->base.vt=(Entry *)D_005D9F38;
 drop(&s->b);
 drop(&s->a);
 s->base.vt=(Entry *)D_005D9E78;
 Rep *r=(Rep *)s->base.str-1;
 if(--r->ref==0)free(r);
 if(flags&1)return func_0050E1A8(s);
}
