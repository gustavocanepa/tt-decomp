/* compiler: ee-gcc2.9-991111 */
typedef int s32;
struct Req { unsigned char type; char pad[3]; s32 m4,m8,mC,m10,m14,m18,m1C,m20,m24,m28,m2C,m30,m34,m38,m3C; };
extern int func_004D6538(struct Req *, int);
extern int func_004D9E40(int);
extern int func_004FB2F0(void);
extern int func_004FA710(void);
extern void func_004FD2D0(const char *, ...);
extern char D_00613C80[], D_00613CC8[];
extern int D_00782900;
int func_004D61E0(int a,int b,int c) {
 struct Req r;
 int x,y;
 if (func_004FB2F0()) return 0x81058007;
 x=func_004D9E40((int)__builtin_return_address(0));
 if(x<0) {func_004FD2D0(D_00613C80); while(1);}
 y=func_004FA710();
 if(y==D_00782900) {func_004FD2D0(D_00613CC8,y); while(1);}
 r.type=8; r.m4=x; r.m8=y; r.mC=0; r.m20=a; r.m24=b; r.m28=c;
 return func_004D6538(&r,0);
}
