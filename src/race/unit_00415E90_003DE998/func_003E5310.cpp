/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 float x,y,z,w;
 V() {}
 V(const V &o) { *(u128 *)this=*(const u128 *)&o; }
 V &operator=(const V &o) { *(u128 *)this=*(const u128 *)&o; return *this; }
 float &at(int i) { return ((float *)this)[i]; }
 float at(int i) const { return ((const float *)this)[i]; }
 const V operator-(const V &o) const { V r(*this); r.at(0)-=o.at(0); r.at(1)-=o.at(1); r.at(2)-=o.at(2); return r; }
 const V operator+(const V &o) const { V r(*this); r.at(0)+=o.at(0); r.at(1)+=o.at(1); r.at(2)+=o.at(2); return r; }
} __attribute__((aligned(16)));
struct M { V rows[3]; };
struct Item { V pos, rot; };
extern "C" Item *func_003E4648(void *, unsigned) throw();
extern "C" M func_003E6160(void *);
extern "C" void func_0044FC00(V *, M *, V *);
static inline V transform(M *m, V *v) { V r; func_0044FC00(&r,m,v); return r; }
extern "C" void func_00453FD0(V *, void *, V *);
static inline V rotate(void *m, V *v) { V r; func_00453FD0(&r,m,v); return r; }
extern "C" void *func_003E5310(void *self, void *arg1, V *origin) {
 M m=func_003E6160(arg1);
 for(int i=0; i<20; ++i) {
  V pos=func_003E4648(self,i)->pos - *origin;
  V rot=func_003E4648(self,i)->rot;
  pos=transform(&m,&pos) + *origin;
  rot=rotate(arg1,&rot);
  func_003E4648(self,i)->pos=pos;
  func_003E4648(self,i)->rot=rot;
 }
 return self;
}
