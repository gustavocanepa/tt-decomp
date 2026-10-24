/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rect { float x,y,z,w; };
struct Item { u32 id; s32 order; Rect a,b; };
struct Obj { char pad[0x14]; s32 retry; Rect r; char pad4[0x10]; u32 id; };
extern "C" s32 func_00213920(Obj *,Rect *,Rect *,float *,float *) throw();
static inline void copy(Rect *d,const Rect *s) { d->x=s->x; d->y=s->y; d->z=s->z; d->w=s->w; }
static inline void shift(Rect *r,float dx,float dy) { r->x+=dx; r->y+=dy; r->z+=dx; r->w+=dy; }
static inline float distance(float a,float b) { float d=a-b; if(d<0.0f) d=-d; return d; }
extern "C" s32 func_00213B30(Obj *o,Item *a,Item *b,float offset) {
    float ax,ay,bx,by;
    Rect ar,ar2,br,br2;
    s32 hitA=0;
    copy(&ar,&a->a); copy(&ar2,&a->b); copy(&br,&b->a); copy(&br2,&b->b);
    shift(&ar,offset,0.0f); shift(&ar2,offset,0.0f); shift(&br,offset,0.0f); shift(&br2,offset,0.0f);
    if(a->id!=o->id) hitA=func_00213920(o,&ar,&ar2,&ax,&ay)!=0;
    s32 hitB=0;
    if(b->id!=o->id) hitB=func_00213920(o,&br,&br2,&bx,&by)!=0;
    if(hitA) {
        if(!hitB) return 1;
        s32 oa=a->order; s32 ob=b->order;
        if(ob<oa) return 1;
        if(oa<ob) return 0;
        if(ay<by) return 1;
        if(by<ay) return 0;
        if(ax<bx) return 1;
        if(bx<ax) return 0;
        float da=(ar.y+ar.w)*0.5f;
        float center=(o->r.y+o->r.w)*0.5f;
        float db=(br.y+br.w)*0.5f;
        da=distance(da,center);
        db=distance(db,center);
        if(da<db) return 1;
        if(db<da) return 0;
        return a->id<b->id;
    }
    if(hitB) return 0;
    if(o->retry && offset==0.0f) return func_00213B30(o,a,b,10000.0f);
    if(a->id==o->id) return 1;
    return b->id==o->id ? 0 : a->id<b->id;
}
