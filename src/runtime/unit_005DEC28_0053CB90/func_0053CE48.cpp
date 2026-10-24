/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int size_t;
inline void *operator new(size_t,void *p) throw() { return p; }
struct Pair {
 float x,y;
 Pair(const Pair &o) { int i=1; const float *q = &o.x + i; x=o.x; y=*q; }
};
template<class T> inline void construct(T *p,const T &o) { new(p) T(o); }
extern "C" Pair *func_0053CE48(Pair *first, Pair *last, Pair *result, int unused0) {
 for(;first!=last;++first,++result) construct(result,*first);
 return result;
}
