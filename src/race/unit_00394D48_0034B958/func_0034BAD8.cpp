/* compiler: ee-gcc2.96-nogcse */
struct Vec { float x,y,z; };
struct Ent { short off,pad; Vec (*fn)(void *,float); };
struct Obj { char *vt; };
struct Handle { Obj *p; };
struct Rec { char pad[0x4840]; Handle *h; };
struct List { char pad[8]; Rec **r; };
struct Course { char pad[0x60]; List *l; };
struct Self { char pad[0x14]; Course *course; };
extern "C" int func_0034B980(Self *,Vec *,float *) throw();
extern "C" float func_004A5B78(float,float);
extern "C" float func_0034BAD8(Self *o,Vec *pos,Vec *dir) {
 float out;
 int i = func_0034B980(o,pos,&out);
 if(i < 0) return 0.0f;
 Course *course = o->course;
 Handle *h = course->l->r[i]->h;
 if (!h) return 0.0f;
 Obj *obj = h->p;
 if (!obj) return 0.0f;
    Ent *e = (Ent *)(obj->vt + 0x28);
    const Vec &v = e->fn((char *)obj+e->off,0.0f);
    float x = v.x-pos->x;
    float z = v.z-pos->z;
    float dz = dir->z;
    float dx = dir->x;
    return func_004A5B78(x*dz-z*dx,x*dx+z*dz);
}
