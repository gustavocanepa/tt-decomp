/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct E { int w0, w1, w2, w3, w4, w5; };
struct Q { int w[9]; };
struct R { int w[66]; };
struct Obj {
    char pad0[0xAC0];
    int c0, c4, c8, cc;
    char padd0[0xAE0 - 0xAD0];
    int e0;
    char pade4[0xD88 - 0xAE4];
    E e[1];
    char padx[0xDCC - 0xD88 - sizeof(E)];
    int dcc, dd0;
    char padd4[0xDE0 - 0xDD4];
    R r[3];
    char padz[0x10F8 - 0xDE0 - 3 * sizeof(R)];
    Q q[6];
};

static inline int readAt(char *p, int off) { return *(int *)(p+off); }
static inline char *row(char *p, unsigned off) { return p+off; }
extern "C" int func_004587D0(Obj *o) {
    if (o->c0 <= 0) return 0;
    if (o->c4 <= 0) return 0;
    if (o->c8 <= 0) return 0;
    if (o->cc <= 0) return 0;
    if (o->e0 < 0) return 0;
    if (o->e0 > 0xFFFF) return 0;
    if(o->dcc<=0) return 0;
    if(o->dd0<=0) return 0;
    int i;
    for(i=0;i<o->c8;i++) {
        int off=i*24+0xD70;
        int d=readAt((char *)o+0x18,off);
        if(d<=0) return 0;
        int m=readAt((char *)o+0x1C,off);
        if(m<=0) return 0;
        if(o->dcc%d) return 0;
        if(o->dd0%m) return 0;
    }
    for(i=0;i<o->c8;i++) {
        int off=i*24+0xD80;
        u32 x=readAt((char *)o+0x14,off);
        u32 y=readAt((char *)o+0x18,off);
        u32 z=*(u32 *)((char *)o + i*24 + 0xD90);
        if(x>=3) return 0;
        if(y>=3) return 0;
        if(z>=3) return 0;
        if(!*(int *)(row((char *)o,x*36)+0x10F8)) return 0;
        if(!*(int *)(row((char *)o,y*36)+0x1164)) return 0;
        if(!*(int *)(row((char *)o,z*264)+0xDE0)) return 0;
    }
    return 1;
}
