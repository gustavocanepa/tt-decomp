/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { char b[16]; };
struct Vec { int alloc; Item *start, *finish, *end; };
extern "C" void free(void *) throw();
extern "C" void *func_004A4690(int, unsigned);
extern "C" void func_005506F0(Item *, Item *, const Item &);
extern "C" Item *func_00550738(Item *, Item *, Item *, Item *);
extern "C" Item *func_00550788(Item *, unsigned, const Item &, Item *);
static inline Item *value_type(Item **) { return 0; }
template<class T> inline T *ucopy(T *first, T *last, T *result) { return func_00550738(first,last,result,value_type(&result)); }
template<class T> inline T *ufill(T *first, unsigned n, const T &x) { return func_00550788(first,n,x,value_type(&first)); }
static inline const unsigned &max(const unsigned &a,const unsigned &b) { return a<b ? b:a; }
static inline Item *allocate(unsigned n) { return n ? (Item *)func_004A4690(16,n*sizeof(Item)) : 0; }
static inline void deallocate(Item *p,unsigned n) { if(p) free(p); }
static inline void destroy_aux(Item *first,Item *last,Item *) { for(;first!=last;++first) {} }
static inline void destroy(Item *first,Item *last) { destroy_aux(first,last,value_type(&first)); }
static inline Item *copy_backward(Item *first,Item *last,Item *result) { for(int n=last-first;n>0;--n) *--result=*--last; return result; }
extern "C" void func_00550380(Vec *self,Item *position,unsigned n,const Item &x) {
  if(n!=0) {
    if((unsigned)(self->end-self->finish)>=n) {
      Item x_copy=x;
      const unsigned elems_after=self->finish-position;
      Item *old_finish=self->finish;
      if(elems_after>n) {
        ucopy(self->finish-n,self->finish,self->finish);
        self->finish+=n;
        copy_backward(position,old_finish-n,old_finish);
        func_005506F0(position,position+n,x_copy);
      } else {
        ufill(self->finish,n-elems_after,x_copy);
        self->finish+=n-elems_after;
        ucopy(position,old_finish,self->finish);
        self->finish+=elems_after;
        func_005506F0(position,old_finish,x_copy);
      }
    } else {
      const unsigned old_size=self->finish-self->start;
      const unsigned len=old_size+max(old_size,n);
      Item *new_start=allocate(len);
      Item *finish1=ucopy(self->start,position,new_start);
      Item *finish2=ufill(finish1,n,x);
      Item *new_finish=ucopy(position,self->finish,finish2);
      destroy(self->start,self->finish);
      deallocate(self->start,self->end-self->start);
      self->start=new_start;
      self->finish=new_finish;
      self->end=new_start+len;
    }
  }
}
