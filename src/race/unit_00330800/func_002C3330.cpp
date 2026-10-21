/* compiler: ee-gcc2.96-nogcse */
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));
struct Image { int f0; char *data; int f8, fC, depth, height, width, f1C, channels; };
#define LOW(r,z,x) __asm__ volatile("pextlb %0, %1, %2" : "=r"(r) : "r"(z), "r"(x))
#define HIGH(r,z,x) __asm__ volatile("pextub %0, %1, %2" : "=r"(r) : "r"(z), "r"(x))
#define MUL(a,b) __asm__ volatile("pmulth $0, %0, %1" : : "r"(a), "r"(b) : "hi", "lo")
#define MADD(a,b) __asm__ volatile("pmaddh $0, %0, %1" : : "r"(a), "r"(b) : "hi", "lo")
#define RESULT(r) __asm__ volatile("pmfhl.lh %0" : "=r"(r))
#define SHIFT(r,x) __asm__ volatile("psrlh %0, %1, 8" : "=r"(r) : "r"(x))
#define LQ(r,p) __asm__ volatile("lq %0, %1" : "=r"(r) : "m"(*(p)))
#define SQ(m,r) __asm__ volatile("sq %1, %0" : "=m"(m) : "r"(r))
#define PACK(r,a,b) __asm__ volatile("ppacb %0, %1, %2" : "=r"(r) : "r"(a), "r"(b))
extern "C" void func_002C3330(Image *dst,int x,int y,Image *src,int alpha,int row,int sx,int sy) {
    if(src->depth != dst->depth) return;
    if(dst->height < row+src->height) return;
    int beta=256-alpha;
    int ss=src->depth*src->channels;
    int ds=src->depth*dst->channels;
    int sr=ss*src->height;
    int dr=ds*dst->height;
    u128 *s=(u128 *)(src->data+sr*(sy*src->width+sx));
    char *dest=dst->data+dr*(x+y*dst->width);
    u128 *d=(u128 *)(dest+ds*row);
    u128 *end=(u128 *)((char *)s+(dr&~15)+16);
    u128 a,b;
    __asm__ volatile("pcpyld %0, %1, %1" : "=r"(a) : "r"(alpha));
    __asm__ volatile("pcpyld %0, %1, %1" : "=r"(b) : "r"(beta));
    __asm__ volatile("pcpyh %0, %1" : "=r"(a) : "r"(a));
    __asm__ volatile("pcpyh %0, %1" : "=r"(b) : "r"(b));
    u128 *pref=s;
    u32 alignmask=~63u;
    u128 sv; LQ(sv,s);
    ++s;
    u128 dv; LQ(dv,d);
    ++d;
    u128 lo,dl;
    LOW(lo,(u128)0,sv);
    MUL(lo,a);
    LOW(dl,(u128)0,dv);
    while(s<end) {
        MADD(dl,b);
        HIGH(lo,(u128)0,sv);
        LQ(sv,s);
        HIGH(dl,(u128)0,dv);
        u128 r; RESULT(r);
        MUL(lo,a);
        LQ(dv,d);
        u128 r0; SHIFT(r0,r);
        MADD(dl,b);
        __asm__ volatile("pref 0, 0x100(%0)" : : "r"(pref));
        pref=(u128 *)((u32)s&alignmask);
        ++s;
        LOW(lo,(u128)0,sv);
        RESULT(r);
        LOW(dl,(u128)0,dv);
        SHIFT(r,r);
        PACK(r,r,r0);
        MUL(lo,a);
        __asm__ volatile("pref 0, 0x100(%0)" : : "r"(d));
        SQ(d[-1],r);
        ++d;
    }
}
