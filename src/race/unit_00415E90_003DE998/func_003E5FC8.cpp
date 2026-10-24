/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct V2 { f32 x, y; };
struct V3 { f32 x, y, z; };
extern V2 D_00585300;
extern V2 D_00585310;
extern V2 D_00585320;
extern V2 D_00585330;
extern V2 D_00585340;
extern V3 D_00585350;
extern V3 D_00585360;
extern V3 D_00585370;
extern V3 D_00585380;
extern V3 D_00585390;
extern V3 D_005853A0;
extern V3 D_005853B0;
static inline void set2(V2 *const p, float x, float y) { p->x=x; p->y=y; }
static inline void set3(V3 *const p, float x, float y, float z) { p->x=x; p->y=y; p->z=z; }
extern "C" void func_003E5FC8(int a, int b) {
    if (b == 0xFFFF && a == 1) set2(&D_00585300, 0,0);
    if (b == 0xFFFF && a == 1) set2(&D_00585310, 1,0);
    if (b == 0xFFFF && a == 1) set2(&D_00585320, 0,1);
    if (b == 0xFFFF && a == 1) set2(&D_00585330, -1,0);
    if (b == 0xFFFF && a == 1) set2(&D_00585340, 0,-1);
    if (b == 0xFFFF && a == 1) set3(&D_00585350, 0,0,0);
    if (b == 0xFFFF && a == 1) set3(&D_00585360, 1,0,0);
    if (b == 0xFFFF && a == 1) set3(&D_00585370, 0,1,0);
    if (b == 0xFFFF && a == 1) set3(&D_00585380, 0,0,1);
    if (b == 0xFFFF && a == 1) set3(&D_00585390, -1,0,0);
    if (b == 0xFFFF && a == 1) set3(&D_005853A0, 0,-1,0);
    if (b == 0xFFFF && a == 1) set3(&D_005853B0, 0,0,-1);
}
