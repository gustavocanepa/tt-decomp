/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z,w; };
struct Obj { char pad[0xA8]; Vec *p; };
extern "C" Vec *func_0020F5C8(Vec *out, Obj *self) {
    Vec *p=self->p;
    if(p) {
        out->x=p->x;
        out->y=p->y;
        out->z=p->z;
        out->w=p->w;
    } else {
        out->y=out->x=0.0f;
        out->w=out->z=1.0f;
    }
    return out;
}
