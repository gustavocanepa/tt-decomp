/* compiler: ee-gcc2.96-no-strict-aliasing */
struct B {unsigned long long pad:4,x0:10,y0:10,x1:10,y1:10,high:20;};
struct S {char pad[0x20];B b;};
extern "C" void func_00469158(S* s,int which,unsigned int x,unsigned int y) {
 switch(which) {
 case 0:s->b.x0=x;s->b.y0=y;return;
 case 1:s->b.x1=x;s->b.y1=y;return;
 }
}
