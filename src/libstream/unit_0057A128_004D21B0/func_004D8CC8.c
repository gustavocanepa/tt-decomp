/* compiler: ee-gcc2.9-991111 */
struct State { int a,b,c,d; char pad[0x20]; int x30,x34,x38; int (*create)(void *,void *); int x40; int (*func_005AE360)(int,int); int (*stat)(int,int,void *); char pad4c[0x34]; char buf[1]; };
extern struct State D_00782940;
int __attribute__((register_precision ($16, 128))) func_004D8CC8(void) {
    int info[16];
    int args[8];
    int r = D_00782940.func_005AE360(D_00782940.a + 2, D_00782940.b);
    D_00782940.x38 = 0;
    if (r < 0) {
        if ((r & 0xffff) != 0x8002) return r;
        args[0]=2;
        args[1]=D_00782940.a+2;
        args[2]=D_00782940.b;
        r=D_00782940.create(args,D_00782940.buf);
        if (r < 0) return r;
        D_00782940.x38=1;
    }
    D_00782940.x34=r;
    r=D_00782940.stat(r,D_00782940.c,info);
    if (r < 0) return r;
    D_00782940.x30=0;
    D_00782940.d=info[4];
    return 0;
}
