/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct V2 { float x,y; float &X() { return x; } float &Y() { return y; } };
struct Pair { V2 a,b; };
struct View { char pad[0x2c]; u32 count; V2 *points; };
struct Obj { char pad[0xE4]; View *view; char padcc[8]; float length; };
struct Entry { short delta,index; void (*fn)(void *,int,void *,int,int); };
struct Render { int z; char *vt; };
extern "C" void func_00373318(View *,float *,float *,float,float);
static inline void lerp(V2 *out, const V2 *a,const V2 *b,float t) {
    out->x = (b->x-a->x)*t+a->x;
    out->y = (b->y-a->y)*t+a->y;
}
static inline void draw(Render *r, V2 *v) {
    Entry *e=(Entry *)(r->vt+0x1D0);
    e->fn((char *)r+e->delta,4,v,0,0);
}
extern "C" void func_0011D898(Obj *self, Render *r,float start,float end) {
    Pair a,ta,b,tb;
    V2 verts[4];
    V2 *points=0;
    View *view=self->view;
    u32 n=view->count-1;
    if(view->count) points=view->points;
    u32 first=(u32)(start*n/self->length);
    u32 last=(u32)(end*n/self->length);
    float sx=self->length*first/n;
    float ex=self->length*last/n;
    float t=(start-sx)*n/self->length;
    float u=(end-ex)*n/self->length;
    lerp(&a.a,&points[first*2],&points[first*2+2],t);
    lerp(&a.b,&points[first*2+1],&points[first*2+3],t);
    lerp(&b.a,&points[last*2],&points[last*2+2],u);
    lerp(&b.b,&points[last*2+1],&points[last*2+3],u);
    func_00373318(view,&ta.a.x,&ta.a.y,a.a.x,a.a.y);
    func_00373318(self->view,&ta.b.x,&ta.b.y,a.b.x,a.b.y);
    func_00373318(self->view,&tb.a.x,&tb.a.y,b.a.x,b.a.y);
    func_00373318(self->view,&tb.b.x,&tb.b.y,b.b.x,b.b.y);
    V2 *p0=&verts[0], *p1=&verts[1];
    p0->x=ta.a.x; p0->y=ta.a.y; p1->x=ta.b.x; p1->y=ta.b.y;
    int limit=last*2;
    for(int i=first*2+2;i<=limit;i+=2) {
        float *x2=&verts[2].X(), *y2=&verts[2].Y();
        float *x3=&verts[3].X(), *y3=&verts[3].Y();
        func_00373318(self->view,x2,y2,points[i].x,points[i].y);
        func_00373318(self->view,x3,y3,points[i+1].x,points[i+1].y);
        draw(r,verts);
        V2 *cur=&verts[0]; cur->x=*x2; cur->y=*y2;
        V2 *prev=&verts[1]; prev->x=*x3; prev->y=*y3;
    }
    verts[2].X()=tb.a.x; verts[2].Y()=tb.a.y; verts[3].X()=tb.b.x; verts[3].Y()=tb.b.y;
    draw(r,verts);
}
