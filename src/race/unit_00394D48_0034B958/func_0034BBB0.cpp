/* compiler: ee-gcc2.96-nogcse */
struct Vec { float x,y,z; };
struct VE { short delta,index; void (*fn)(Vec *, char *, float); };
struct Obj { char *vt; };
struct Holder { Obj *p; };
struct Car { char pad[0x4840]; Holder *h; };
struct List { unsigned n; int pad; Car **items; };
struct Data { char pad[0x60]; List *list; };
struct Course { char pad[0x14]; Data *data; };
extern "C" float D_005F4100;
extern "C" float func_0034BBB0(Course *self, Vec *pos) {
    Vec dir, point;
    if (!self->data) return 0.0f;
    {
        List *list = self->data->list;
        float best = D_005F4100;
        unsigned i=0;
        if (list->n) do {
            Vec *pt = &point;
            Holder *h = list->items[i]->h;
            if (h) {
                Obj *p = h->p;
                if (p) {
                    VE *a = (VE *)(p->vt + 0x30);
                    a->fn(&dir, (char *)p + a->delta, 0.0f);
                    VE *b = (VE *)(p->vt + 0x28);
                    b->fn(pt, (char *)p + b->delta, 0.0f);
                    float x=pos->x-pt->x;
                    float y=pos->y-pt->y;
                    float z=pos->z-pt->z;
                    float dot=dir.x*x+dir.y*y+dir.z*z;
                    float sq=x*x+y*y+z*z;
                    float t=sq*(1.0f/dot);
                    if (__builtin_fabsf(t) < __builtin_fabsf(best)) best=t;
                }
            }
            i++;
        } while (i < list->n);
        return best;
    }
}
