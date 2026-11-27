/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
    float x,y,z,w;
    float &operator[](int n) { return *(float *)((char *)this+n*4); }
    V() {}
    V(float a,float b,float c) { x=a; y=b; z=c; }
    V(const V &v) { *(u128 *)this=*(const u128 *)&v; }
    V &operator=(const V &v) { *(u128 *)this=*(const u128 *)&v; return *this; }
    V operator+(const V &v) const { V r(*this); r[0]+=v.x; r[1]+=v.y; r[2]+=v.z; return r; }
} __attribute__((aligned(16)));
struct Self { int flag; char pad[12]; V pos,dir,axis; float a,b; char pad48[8]; V *source; };
extern "C" V func_003E6350(char *, const V &);
extern "C" int FreeHandleSolver__solve(Self *self, int unused1, int unused2, char *ctx) {
    if(self->flag==0) {
        self->pos = *self->source + V(0x1.999998p-5f,0x1.999998p-3f,0x1.333332p-2f);
        self->dir = V(0.0f,-1.0f,0.0f);
        self->axis = V(0x1.bb67aep-1f,0.0f,0.5f);
    } else {
        self->pos = *self->source + V(-0x1.999998p-5f,0x1.999998p-3f,0x1.333332p-2f);
        self->dir = V(0.0f,-1.0f,0.0f);
        self->axis = V(-0x1.bb67aep-1f,0.0f,0.5f);
    }
    self->dir = func_003E6350(ctx+0x10,self->dir);
    self->axis = func_003E6350(ctx+0x10,self->axis);
    self->a = 0.5f;
    self->b = 1.0f;
    return 0;
}
