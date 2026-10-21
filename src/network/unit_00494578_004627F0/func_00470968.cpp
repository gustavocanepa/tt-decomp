typedef unsigned long long u64;
struct Scissor { u64 x0:11; u64 p0:5; u64 x1:11; u64 p1:5; u64 y0:11; u64 p2:5; u64 y1:11; u64 p3:5; };
struct Obj {
 char p0[10]; unsigned char clip; char p1[0x190-11];
 Scissor scissor; char p2[0x1d8-0x198]; u64 flags;
 char p3[0x264-0x1e0]; int width,height;
 char p4[0x288-0x26c]; int x,y,w,h,cx,cy,cw,ch;
};
static inline int maxv(int a,int b) { if(a<b) a=b; return a; }
extern "C" void func_00470968(Obj *p) {
 int x=p->x, y=p->y;
 int x1=x+p->w, y1=y+p->h;
 if (x1>p->width) x1=p->width;
 x=maxv(x,0);
 y=maxv(y,0);
 if (y1>p->height) y1=p->height;
 if (p->clip) {
  int cx=p->cx,cy=p->cy;
  int xx=cx+p->cw;
  if(x<cx) x=cx;
  int yy=cy+p->ch;
  if(x1>xx) x1=xx;
  if(y<cy) y=cy;
  if(y1>yy) y1=yy;
 }
 if ((x1<x)|(y1<y)) {
  p->scissor.x0=0; p->scissor.y0=0; p->scissor.x1=0; p->scissor.y1=0;
 } else {
  p->scissor.x0=x; p->scissor.y0=y; p->scissor.x1=x1-1; p->scissor.y1=y1-1;
 }
 p->flags |= 0x100010;
}
