/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P { float x,y; };
struct E { P *a,*b; int flag; };
struct Comp { unsigned char c; };
struct S { E values[1024]; int count; Comp comp; };
extern "C" void func_0055BD50(S *,E *);
extern "C" void func_0055BD98(E *,int,int,E *,Comp);
static inline P *func_005AE2E8(P *const &p) { return p; }
extern "C" void func_0055B380(S *s,P *a,P *b) {
    E v;
    struct { E *first; Comp c0,c1; } state;
    int spare[4];
    E tmp;
    if(func_005AE2E8(a)->y < func_005AE2E8(b)->y || (func_005AE2E8(a)->y == func_005AE2E8(b)->y && func_005AE2E8(a)->x < func_005AE2E8(b)->x)) { v.a=a; v.b=b; v.flag=1; }
    else { v.a=b; v.b=a; v.flag=0; }
    func_0055BD50(s,&v);
    state.first=s->values; state.c1=s->comp; state.c0=state.c1;
    E *end=s->values+s->count;
    int length=end-s->values;
    tmp=*(end-1);
    func_0055BD98(s->values,length-1,0,&tmp,state.c1);
}
