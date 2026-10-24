/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
 union { unsigned int word; struct { unsigned char kind,xflag,yflag,pad3; } b; } u;
 short x,y,w,h;
 float opacity;
 int m10;
 void *vptr;
};
extern "C" char D_005D5B50[];
extern "C" int RaceDisplayObjectBase__structor_0(Obj *p) {
 p->vptr = D_005D5B50;
 p->u.word &= ~0xffu;
 p->u.b.xflag = 2;
 p->u.b.yflag = 2;
 p->x = 0;
 p->y = 0;
 p->w = 0;
 p->h = 0;
 p->opacity = 1.0f;
 p->m10 = 0;
}
