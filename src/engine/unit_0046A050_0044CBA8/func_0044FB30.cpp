/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V2 {float x,y;};
struct M2 {float m[4];};
extern "C" void func_0044FAE0(V2 *,const M2 *,const V2 *) throw();
extern "C" void func_0044FB30(V2 *v,const M2 *m) {
    V2 r __attribute__((aligned(16)));
    func_0044FAE0(&r,m,v);
    *(u128*)v=*(u128*)&r;
}
