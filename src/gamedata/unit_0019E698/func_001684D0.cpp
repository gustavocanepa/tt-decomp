/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char pad[8]; unsigned char a,b; signed char c,d; char tail[4]; };
struct Data { int n; char pad[12]; Entry entries[1]; };
struct VEntry { short delta,index; int (*fn)(void *); };
struct Obj { int x; char *vt; char pad[8]; Data *data; };
struct Handle { Obj *p; };
extern "C" void func_001680E8(void *,void *) throw();
extern "C" void func_00168090(void *,int) throw();
extern "C" void func_00293220(void *,void *);
extern "C" void func_002931C8(void *,int);
extern "C" int func_00294F40(void *);
extern "C" void func_002951D0(void *,int);
extern "C" Handle *func_00295260(void *,int);
extern "C" void func_0029EA18(void *,int);
extern "C" void func_0029CEF0(void *,int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void func_003FE9A8(void *,int);
static inline int number(Handle *h) {
 Obj *obj=h->p;
 VEntry *v=(VEntry*)(obj->vt+0x68);
 return v->fn((char*)obj+v->delta);
}
static inline void assign(Handle *dst,Handle *src) {
 if(dst!=src) { Obj *p=src->p; if(p)func_002C0FE8(p); if(dst->p)func_002C1050(dst->p); dst->p=p; }
}
struct Slot { Handle h; char pad[12]; };
struct Array : Handle {
 char pad[12];
 Array(int n) {func_002951D0(this,n);}
 ~Array() {func_002931C8(this,2);}
 Handle *index(int n) {return func_00295260(this,n);}
};
struct Integer : Handle {
 char pad[12];
 Integer(int n) {func_0029EA18(this,n);}
 ~Integer() {func_0029CEF0(this,2);}
};
extern "C" void func_001684D0(Handle *ret,void *arg,int mode,Handle *input) {
 Slot f[2];
 func_001680E8(&f[0].h,arg);
 Data *data=f[0].h.p->data;
 func_00168090(&f[0].h,2);
 if(mode>0) {
  func_00293220(&f[0].h,input);
  int i=0;
  int count=func_00294F40(f[0].h.p);
  if(i<count) {
   Handle *row=&f[1].h;
   Entry *e=data->entries;
   do {
    func_00293220(row,func_00295260(&f[0].h,i));
    i++;
    int d=number(func_00295260(row,0));
    int a=number(func_00295260(row,1));
    int b=number(func_00295260(row,2));
    int c=number(func_00295260(row,3));
    e->d=d; e->c=c; e->a=a; e->b=b;
    e++;
    func_002931C8(row,2);
   } while(i<count);
  }
  func_003FE9A8(data,count);
  func_002931C8(&f[0].h,2);
 } else {
  int count=data->n;
  int i=0;
  func_002951D0(&f[0].h,count);
  if(i<count) {
   Entry *e=data->entries;
   do {
    { Array row(4);
    {Handle *dst=row.index(0); Integer value(e->d); assign(dst,&value);}
    {Handle *dst=row.index(1); Integer value(e->a); assign(dst,&value);}
    {Handle *dst=row.index(2); Integer value(e->b); assign(dst,&value);}
    {Handle *dst=row.index(3); Integer value(e->c); assign(dst,&value);}
    assign(func_00295260(&f[0].h,i),&row); }
    i++;
    e++;
   }while(i<count);
  }
  assign(ret,&f[0].h);
  func_002931C8(&f[0].h,2);
 }
}
