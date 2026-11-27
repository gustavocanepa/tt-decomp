/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P { float x,y; };
struct Array { P *data[32]; int count,flag; };
struct Tri { float x0,y0,x1,y1,x2,y2; };
struct Out { int remaining,unused; Tri *next; };
extern "C" void func_0055C660(Array *,P **);
extern "C" void func_0055C690(Array *,unsigned int,int);
static inline P *func_005AE2E8(P *const &p) { return p; }
static inline P *get(Array *s,int i) { return s->data[i]; }
static inline void emit(Out *out,P *a,P *b,P *c) {
    if(out->remaining>0) {
        out->next->x0=a->x; out->next->y0=a->y;
        out->next->x1=b->x; out->next->y1=b->y;
        out->next->x2=c->x; out->next->y2=c->y;
        out->next=out->next+1;
        out->remaining=out->remaining-1;
    }
}
extern "C" void func_0055BFD0(Array *s,Out *out,P *p,int flag) {
    int n=s->count;
    if(n<2) { func_0055C660(s,&p); s->flag=flag; return; }
    if(flag==s->flag) {
        P *previous=get(s,n-1);
        float dx=func_005AE2E8(previous)->x-func_005AE2E8(p)->x;
        float dy=func_005AE2E8(previous)->y-func_005AE2E8(p)->y;
        P **end=(P **)(n*4+(int)s);
        P **cursor=end-2;
        int k=2;
        P *current;
        P **currentRef=&current;
        int j=n-2;
        int kept;
        for(;k<=n;k++) {
            current=*cursor--;
            kept=j--;
            float nx=(*currentRef)->x-func_005AE2E8(p)->x;
            float ny=(*currentRef)->y-func_005AE2E8(p)->y;
            float cross=dx*ny-dy*nx;
            dy=ny; dx=nx;
            if(flag) cross=-cross;
            if(!(cross<0.0f)) goto resize;
            emit(out,current,previous,p);
            previous=current;
        }
        kept=n-k;
resize:
        func_0055C690(s,kept+2,0);
        func_0055C660(s,&p);
    } else {
        s->flag=flag;
        int last=n-1;
        for(int i=0;i<n-1;) { int next=i+1; emit(out,s->data[i],s->data[next],p); i=next; }
        s->data[0]=s->data[last]; s->data[1]=p;
        func_0055C690(s,2,0);
    }
}
