/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rect { int x,y,w,h; Rect() {} Rect(int a,int b,int c,int d):x(a),y(b),w(c),h(d) {} };
struct View { int a[4]; int x,y,w,h; int b[7]; };
struct Obj { char pad[0x2c]; View v; int n; Rect r[5]; };
extern "C" void func_00104A88(View*,int);
extern "C" void func_00104C88(View*);
extern "C" void func_00104D10(View*);
extern "C" void func_00472268(int,int);
extern "C" void func_00472528(int,int,int);
extern "C" void func_00472628();
extern "C" void func_00474520(float,float,float,float,float,float,float,float);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void func_00478C98(int);
extern "C" void func_0038C288(Obj *o,View *v) {
 View *own=&o->v;
 int width=own->x+own->w;
 int height=own->y+own->h;
 o->r[0]=Rect(0,0,width/2,height);
 o->r[1]=Rect(width/2,0,width/2,height/2);
 o->r[2]=Rect(width/2,height/2,width/4,height/2);
 o->r[3]=Rect(width*3/4,height/2,width/4,height/4);
 o->r[4]=Rect(width*3/4,height*3/4,width/4,height/4);
 o->n=4; own->a[1]=1;
 func_00104A88(own,0); own->b[3]=0;
 int x=0,y=0;
 int w=v->x+v->w,h=v->y+v->h;
 func_00478C98(4);func_00478C98(6);func_00478C98(5);
 func_00477E30(1.0f,1.0f,1.0f,1.0f);
 func_00104C88(own);func_00104D10(v);
 func_00472268(3,1);func_00472268(2,1);
 for(int i=0;i<o->n+1;i++) {
  if(i==1)func_00104D10(own);
  int sx=x,sy=y;
  int ex=w,ey=h;
  x=o->r[i].x; y=o->r[i].y;
  w=o->r[i].w;h=o->r[i].h;
  func_00472268(4,2);func_00472268(5,2);
  func_00472528(0,sx,sx+ex-1);func_00472528(1,sy,sy+ey-1);
  func_00472268(2,1);
  func_00474520((float)x,(float)y,(float)(x+w),(float)(y+h),(float)sx,(float)sy,(float)(sx+ex),(float)(sy+ey));
  func_00472628();
 }
}
