/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z,w; };
struct Data { char pad[16]; Vec v; };
struct Obj { char pad[0xA8]; Data *p; };
extern "C" Vec *func_0020F878(Vec *out,Obj *self) {
    Data *p=self->p;
    Vec *v=&p->v;
    if(p) {
        out->x=v->x;
        out->y=v->y;
        out->z=v->z;
        out->w=v->w;
    } else {
        out->y=out->x=0.0f;
        out->w=out->z=1.0f;
    }
    return out;
}
