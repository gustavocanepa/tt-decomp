struct Vec { float x,y,z; };
struct Obj { char pad[0x6c]; float angle; };
struct Input { char pad[0x30]; float width,height; };
extern "C" float func_004A5C50(float);
extern "C" float func_004A5D18(float) throw();
extern "C" void func_00319EC0(Obj *, Vec *, Vec *) throw();
inline void set(Vec *v, float x, float y, float z) { v->x=x; v->y=y; v->z=z; }
extern "C" void func_0031A038(Obj *o, Input *in) {
    Vec a,b;
    Vec *pb = &b;
    float rad = o->angle * 0x1.921fb4p+1f / 180.0f;
    float h = in->height * 0x1.111110p-3f;
    float w = in->width * 0x1.111110p-3f;
    float s = func_004A5C50(rad);
    float c = func_004A5D18(rad);
    set(&a, s*w, 0.0f, c*w);
    set(pb, -c*h, 0.0f, s*h);
    func_00319EC0(o, &a, pb);
}
