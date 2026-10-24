/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk24 { int a,b,c; unsigned short d,e,f,g; int h; };
extern char D_0059D4A8[];
extern "C" float func_004C7048(void *, float);
extern "C" Blk24 *func_004C78C0(void *, int);
extern "C" void func_004C7668(void *, int, Blk24 *);
extern "C" void func_0042C188() {
    func_004C7048(D_0059D4A8,60.0f);
    int i=0;
    int color=0x1fffff;
    do {
        Blk24 b=*func_004C78C0(D_0059D4A8,i);
        b.c=4;
        b.d=0xfff;
        b.e=0xfff;
        b.g=0;
        b.f=0;
        b.b=0;
        b.a=1;
        b.h=color;
        color-=0x20000;
        func_004C7668(D_0059D4A8,i,&b);
        ++i;
    } while(i<2);
}
