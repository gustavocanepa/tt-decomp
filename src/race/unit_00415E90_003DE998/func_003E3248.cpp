/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {u128 q; V &operator=(const V &v) { q=v.q;return *this; }};
struct S { V origin; V rows[6]; V a[2]; V b[2]; V end; };
extern "C" S *func_003E3248(S *d,const S *s) {
 int i;
 d->origin=s->origin;
 d->end=s->end;
 for(i=0;i<6;i++) d->rows[i]=s->rows[i];
 for(i=0;i<2;i++) { d->a[i]=s->a[i]; d->b[i]=s->b[i]; }
 return d;
}
