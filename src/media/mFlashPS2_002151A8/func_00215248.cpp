/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0043D510(void *);
extern "C" void func_004A45D0(void *) throw();
extern "C" void func_0050E1A8(void *) throw();
struct E12 { int data[3]; ~E12() {} };
struct E8 { int data[2]; ~E8() { func_0043D510(this); } };
struct FreeNode { FreeNode *next; };
extern FreeNode *D_005A4C64[];
struct Rep { int len, cap, ref, sel; };
struct Link { char pad[4]; Link *prev, *next; };
struct VEntry { short delta, index; void (*fn)(void *,int); };
struct Obj { char pad[0x5c]; char *vt; };
struct Vec12 { E12 *first, *last, *cap; };
struct Large {
 Obj *obj; Large *prev, *next;
 char pad0[0x15c];
 char *str168;
 char pad1[8];
 char handle174[8];
 char *str17c;
 Vec12 vec;
 char handle18c[8];
};
struct Small { int allocator; E8 *first, *last, *cap; };
struct Self { char pad[12]; void *data; Large *large; Small *small; int ownsData, ownsObjects; };
template<class T> static inline T *value_type(T *const &) { return (T *)0; }
template<class T> static inline void destroy_aux(T *first, T *last, T *) { for(;first!=last;++first) first->~T(); }
template<class T> static inline void destroy(T *first, T *last) { destroy_aux(first,last,value_type(first)); }
static inline void dealloc(E12 *p, unsigned n) {
 if (n) {
   unsigned bytes = n*sizeof(E12);
   if (bytes > 128) func_004A45D0(p);
   else { FreeNode **q = D_005A4C64 + (bytes+7)/8; ((FreeNode *)p)->next = *q; *q=(FreeNode *)p; }
 }
}
static inline void clearVec(Vec12 *v) { destroy(v->first, v->last); dealloc(v->first, v->cap-v->first); }
static inline void release(char *p) {
 Rep *r = (Rep *)(p-16);
 if (--r->ref == 0) func_004A45D0(r);
}
extern "C" void func_00215248(Self *self) {
 void *p = self->data;
 self->data = 0;
 if (self->ownsData && p) { func_004A45D0(p); self->ownsData=0; }
 if (self->ownsObjects) {
   Large *a = self->large;
   Small *b = self->small;
   self->large=0; self->small=0;
   if (a) {
      func_0043D510(a->handle18c);
      clearVec(&a->vec);
      release(a->str17c);
      func_0043D510(a->handle174);
      release(a->str168);
      if (a->prev == a->next) {
        Obj *o=a->obj;
        if (o) { VEntry *v=(VEntry *)(o->vt+8); v->fn((char *)o+v->delta,3); }
      } else {
        a->next->prev=a->prev;
        a->prev->next=a->next;
      }
      func_0050E1A8(a);
   }
   if (b) {
      destroy(b->first,b->last);
      if(b->first) func_004A45D0(b->first);
      func_0050E1A8(b);
   }
 }
}
