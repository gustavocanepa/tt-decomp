/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P8 { long v; } __attribute__((packed,aligned(4)));
struct P12 { long v; int z; } __attribute__((packed,aligned(4)));
struct Pair { int x,y; };
extern "C" void func_0045D0B0(void *);
extern "C" void func_00456C68(char *self, P12 *src, P8 *arg) {
 Pair *p=(Pair *)(self+0x888);
 *(P12 *)(self+0x87c)=*src;
 *(P8 *)(self+0x8e0)=*arg;
 func_0045D0B0(p);
 p->x=((Pair *)src)->x;
 *(int *)(self+0x88c)=((Pair *)src)->y;
 *(int *)(self+0x8dc)=0x5f;
 *(int *)(self+4)=0;
 *(int *)(self+0x8c4)=2;
 *(int *)(self+0x8cc)=1;
 *(int *)(self+0x8d0)=1;
 *(int *)(self+0x8d4)=1;
 *(int *)(self+0x8d8)=1;
 *(int *)(self+0)=1;
 *(int *)(self+0x8c8)=2;
}
