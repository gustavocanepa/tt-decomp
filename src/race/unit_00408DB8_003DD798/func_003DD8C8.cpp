/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 u128 v;
 V &operator=(const V &a){v=a.v;return *this;}
};
struct M {u128 a,b,c;M &operator=(const M &m){a=m.a;b=m.b;c=m.c;return *this;}};
struct S {char p[0x20];V v[9];V u[3];float e;char pe[12];M m;int a;float b,c;int d;float f;};
extern "C" S *func_003DD8C8(S *s,const S *o){
 for(int i=0;i<9;i++) s->v[i]=o->v[i];
 for(int i=0;i<3;i++) s->u[i]=o->u[i];
 s->e=o->e;
 s->m=o->m;
 s->a=o->a;s->b=o->b;s->c=o->c;s->d=o->d;s->f=o->f;
 return s;
}
