/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x,y; };
struct Poly { int n; V pts[1]; };
struct State { int kind; V pos; int hits,index,edge,vertex,flags; float angle; };
struct Result { int kind; V pos; int vertex; };
extern "C" void func_00378858(State *, V *) throw();
extern "C" float func_00378908(V *,V *,V *) throw();
extern "C" float func_00378948(Result *, V *,V *,int,int,V *,V *,float) throw();
extern "C" float func_004EE530(float);
static inline float sum(float a,float b) { return a+b; }
static inline float subx(V *a,V *b) { return a->x-b->x; }
static inline float suby(V *a,V *b) { return a->y-b->y; }
static inline float root(float x) { __asm__ volatile("sqrt.s %0, %0" : "+f"(x)); return x; }
static inline void update(State *s,int kind,float x,float y,int vertex,float angle) {
 s->kind=kind; s->pos.x=x; s->pos.y=y; s->hits=1; s->vertex=vertex; s->flags=0; s->angle=angle;
}
extern "C" float func_00378FD8(Poly *p,int unused,V *from,V *to,State *s,int inside) {
    Result r;
    float zero=0.0f;
    int edge = 0;
    int prev = p->n - 1;
    V *b = (V *)((char *)p+p->n*8-4);
    V *a = &p->pts[0];
    if (s->edge > 0) {
        char *q = (char *)p+s->edge*8;
        edge = s->edge;
        prev = edge-1;
        a = (V *)(q+4);
        b = (V *)(q-4);
    }
    if (func_00378908(b,to,a) > zero) {
        if (inside) func_00378858(s,to);
zero_return:
        return 0.0f;
    }
    float angle = 0.0f;
    float dx = subx(a,b);
    float dy = suby(a,b);
    float vx = subx(to,from);
    float vy = suby(to,from);
    float dot2 = dx*vx + dy*vy;
    float len1 = dx*dx + dy*dy;
    float len2 = vx*vx + vy*vy;
    if (len1 <= angle) goto zero_return;
    if (len2 <= angle) goto zero_return;
    __asm__ volatile("sqrt.s %0, %1" : "=f"(len1) : "f"(len1));
    __asm__ volatile("sqrt.s %0, %1" : "=f"(len2) : "f"(len2));
    float cosine = __builtin_fabsf(dot2/(len1*len2));
    angle = ((0x1.921fb4p+0f-func_004EE530(cosine))*180.0f)/0x1.921fb4p+1f;
    if (cosine < 0x1.333332p-2f) return 0.0f;
    float result = func_00378948(&r,b,a,prev,edge,from,to,cosine);
    update(s,r.kind,r.pos.x,r.pos.y,r.vertex,angle);
    return result;
}
