/* compiler: ee-gcc2.96-nogcse */
struct Vec { float x,y,z; };
struct VE { short delta,index; Vec (*fn)(void *,float); };
struct Obj { char *vt; };
struct Handle { Obj *p; };
struct Item { char pad[0x4840]; Handle *h; };
struct List { int n; int pad; Item **items; };
struct Block { char pad[0x60]; List *list; };
struct Self { char pad[0x14]; Block *b; };
extern float D_005F40FC;
extern "C" unsigned func_0034B980(Self *o, Vec *v, float *out) {
    Block *b = o->b;
    if (!b) return -1U;
    {
        List *l = b->list;
        float best = D_005F40FC;
        int i=0;
        unsigned index=0;
        if (l->n != 0) do {
            Handle *h = l->items[i]->h;
            if (h) {
                Obj *p = h->p;
                if (p) {
                    VE *e = (VE *)(p->vt + 0x28);
                    Vec pos = e->fn((char *)p + e->delta, 0.0f);
                    float x=v->x-pos.x, y=v->y-pos.y, z=v->z-pos.z;
                    float d=x*x + y*y + z*z;
                    if (d < best) { best=d; index=i; }
                }
            }
            i++;
        } while ((unsigned)i < (unsigned)l->n);
        *out = best;
        return index;
    }
}
