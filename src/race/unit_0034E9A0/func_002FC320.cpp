/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pos { float x,y,z; Pos() {} Pos(float a, float b, float c) : x(a), y(b), z(c) {} };
struct Vec { float x,y,z; int tag; };
struct Body { Pos p; Pos dir; char pad[0x4C8-24]; int tag; };
struct Car { char pad[0x10]; float *dist; char gap[0x104-0x14]; Body body; };
struct Self { char pad[0x20A20]; void *course; };
extern "C" float func_0034B268(void *, Vec *);
extern "C" float func_002FC320(Self *self, Car *car) {
    Body *b = &car->body;
    float d = *car->dist;
    Vec v;
    Pos p(b->p.x + b->dir.x*d, b->p.y + b->dir.y*d, b->p.z + b->dir.z*d);
    v.x = p.x;
    v.y = p.z;
    v.z = -p.y;
    v.tag = b->tag;
    return func_0034B268(self->course, &v);
}
