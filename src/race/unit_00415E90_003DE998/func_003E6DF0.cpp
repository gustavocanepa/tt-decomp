/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
union Q {float v[4];u128 q;};
static inline Q *rot(Q *q,int k,float s,float c) {
 Q t;
 t.v[0]=c*q->v[0]-s*q->v[1];
 t.v[1]=c*q->v[1]+s*q->v[0];
 t.v[k]=s*q->v[3]+c*q->v[k];
 t.v[3]=c*q->v[3]-s*q->v[k];
 q->q=t.q;
 return q;
}
extern "C" Q *func_003E6DF0(Q *q,float s,float c) {return rot(q,2,s,c);}
