/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 { union { struct { float x,y,z; }; float v[3]; }; };
struct Box { float lo[3], hi[3]; };
struct Obj { char pad[0x80]; unsigned char *nodes; };
extern "C" int func_003848F8(Obj *, void *, const Vec3 *, const Vec3 *, int);
extern "C" int GT4Course__RunwayData__traverse(Obj *o, void *out, const Box *box, const Vec3 *from, const Vec3 *to, int off, int depth, int index) {
    if(depth < 0) return func_003848F8(o,out,from,to,index);
    unsigned char node = o->nodes[off];
    int axis = node >> 6;
    float frac = ((int)(node & 63) + 0.5f) * 0.015625f;
    float split = box->lo[axis]*(1.0f-frac) + box->hi[axis]*frac;
    float df = ((const float *)from)[axis]-split;
    float dt = ((const float *)to)[axis]-split;
    index *= 2;
    if(df*dt < 0.0f) {
        Vec3 mid;
        float a = 1.0f/(((const float *)to)[axis]-((const float *)from)[axis]);
        float b = (split-((const float *)from)[axis])*a;
        a = dt * (1.0f/(((const float *)to)[axis]-((const float *)from)[axis]));
        mid.x = a*from->x + b*to->x;
        mid.y = a*from->y + b*to->y;
        mid.z = a*from->z + b*to->z;
        mid.v[axis]=split;
        Box cut=*box;
        if(df < 0.0f) {
            cut.hi[axis]=split;
            if(GT4Course__RunwayData__traverse(o,out,&cut,from,&mid,off+1,depth-1,index)) return 1;
            cut.lo[axis]=split;
            cut.hi[axis]=box->hi[axis];
            if(GT4Course__RunwayData__traverse(o,out,&cut,&mid,to,off+(1<<depth),depth-1,index+1)) return 1;
        } else {
            cut.lo[axis]=split;
            if(GT4Course__RunwayData__traverse(o,out,&cut,from,&mid,off+(1<<depth),depth-1,index+1)) return 1;
            cut.lo[axis]=box->lo[axis];
            cut.hi[axis]=split;
            if(GT4Course__RunwayData__traverse(o,out,&cut,&mid,to,off+1,depth-1,index)) return 1;
        }
    } else {
        if(df < 0.0f) {
            Box cut=*box;
            cut.hi[axis]=split;
            if(GT4Course__RunwayData__traverse(o,out,&cut,from,to,off+1,depth-1,index)) return 1;
        } else {
            Box cut=*box;
            cut.lo[axis]=split;
            if(GT4Course__RunwayData__traverse(o,out,&cut,from,to,off+(1<<depth),depth-1,index+1)) return 1;
        }
    }
    return 0;
}
