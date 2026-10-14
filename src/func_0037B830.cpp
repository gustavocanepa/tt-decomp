/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S;
struct Out { float x,y,z; };
struct In { int pad; S *self; };
extern "C" float func_002E6150(S *, int);
extern "C" float func_002E61E8(S *, int, float);
extern "C" float func_002E62B8(S *, int, float);
extern "C" void *func_0037B830(Out *out, In *in, int idx, float f) {
    int n = *((signed char *)in + idx + 12);
    float x = func_002E6150(in->self,n);
    float y = func_002E61E8(in->self,n,f);
    float z = func_002E62B8(in->self,n,f);
    out->x=x;
    out->y=y;
    out->z=z;
    return out;
}
