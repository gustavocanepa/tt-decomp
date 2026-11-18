/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z,w; };
struct Segment { char p0[16]; Vec v; void *vt; char p24[28]; float a,b; char p48[8]; };
struct Face { Segment s; char p50[32]; };
struct Self { Face f; Segment a0,a1,a2,a3,a4,a5,a6,a7; Face g; Segment b0,b1,b2,b3,b4,b5,b6,b7,b8,b9; };
extern char D_005D71E8[], D_005D7238[];
extern "C" int func_003E3A60(Self*,void*);
static inline void vec(Vec *v) { v->x=0.0f; v->y=0.0f; v->z=0.0f; v->w=1.0f; }
static inline void seg(Segment *s,void *vt) { vec(&s->v); s->vt=vt; s->a=0.0f; s->b=0.0f; }
static inline void face(Face *s) { vec(&s->s.v); s->s.a=0.0f; s->s.b=0.0f; s->s.vt=D_005D71E8; }
extern "C" int func_003E3680(Self *s, void *arg1) {
face(&s->f);
seg(&s->a0,D_005D7238); seg(&s->a1,D_005D7238); seg(&s->a2,D_005D7238); seg(&s->a3,D_005D7238);
seg(&s->a4,D_005D7238); seg(&s->a5,D_005D7238); seg(&s->a6,D_005D7238); seg(&s->a7,D_005D7238);
face(&s->g);
seg(&s->b0,D_005D7238); seg(&s->b1,D_005D7238); seg(&s->b2,D_005D7238); seg(&s->b3,D_005D7238);
seg(&s->b4,D_005D7238); seg(&s->b5,D_005D7238); seg(&s->b6,D_005D7238); seg(&s->b7,D_005D7238); seg(&s->b8,D_005D7238); seg(&s->b9,D_005D7238);
return func_003E3A60(s,arg1);
}
