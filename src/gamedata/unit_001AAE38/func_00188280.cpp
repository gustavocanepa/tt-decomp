/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Item { int off,w,h,x,y; };
struct Context { char pad[0x10]; unsigned char alpha; };
struct Vec2 { float x,y; char pad[8]; };
struct Vec3 { float x,y,z; };
struct Tex2 { float x,y; };
extern "C" void func_003EBCF8(Context *,Vec2 *);
extern "C" int func_004677B0(int,int,int,void *);
extern "C" void func_00472268(int,int);
extern "C" void func_00472528(int,u32,u32);
extern "C" void func_00478C98(int);
extern "C" void func_0046F0F8(int);
extern "C" void func_00470478(int);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void func_004702D8(int,float);
extern "C" void *func_00473980(int);
extern "C" void func_0046D810(int,void *,void *,int,int,int);
static inline u32 pow2(u32 n) {
    u32 z;
    __asm__("plzcw %0, %1" : "=r"(z) : "r"(n-1));
    return 1u << ((z & 31) ^ 31);
}
static inline void vertex(Vec3 *p,float x,float y,float z) { p->x=x;p->y=y;p->z=z; }
static inline void tex(Tex2 *p,float x,float y) { p->x=x;p->y=y; }
extern "C" void func_00188280(char *base,Item *item,Context *ctx) {
    Vec2 a,b;
    int w = item->w;
    int h = item->h;
    float fw = (float)w;
    float fh = (float)h;
    a.x=(float)item->x;
    a.y=(float)item->y;
    float alpha = (float)ctx->alpha / 255.0f;
    b.x=a.x+fw;
    b.y=a.y+fh;
    func_003EBCF8(ctx,&a);
    func_003EBCF8(ctx,&b);
    func_004677B0(1,w,h,base+item->off*3);
    func_00472268(4,2);
    func_00472268(5,2);
    func_00472528(0,0,w-1);
    func_00472528(1,0,h-1);
    func_00472268(3,1);
    func_00472268(2,1);
    func_00478C98(5);
    func_00478C98(4);
    func_0046F0F8(6);
    func_00470478(0);
    func_00477E30(1.0f,1.0f,1.0f,alpha);
    func_004702D8(100,alpha);
    float y,x,x2,y2;
    x=a.x; y=a.y; x2=b.x; y2=b.y;
    float *v=(float *)func_00473980(3);
    float *t=(float *)func_00473980(2);
    float u = (float)(u32)w / (float)pow2(w);
    float tv = (float)(u32)h / (float)pow2(h);
    v[0]=x;
    v[1]=y;
    v[3]=x2;
    v[7]=y2;
    v[4]=y;
    v[6]=x;
    v[9]=x2;
    v[10]=y2;
    v[2]=0.0f;
    v[5]=0.0f;
    v[8]=0.0f;
    v[11]=0.0f;
    t[2]=u;
    t[6]=u;
    t[0]=0.0f;
    t[1]=0.0f;
    t[3]=0.0f;
    t[4]=0.0f;
    t[5]=tv;
    t[7]=tv;
    func_0046D810(4,v,t,0,0,0);
}
