/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y; };
struct Obj { int state,w,h,padC,type; Vec focus,lo,hi; int duration,fade,p34,time,p3C,count,reverse,enabled; float a,b; };
struct Out { float x,y,w,h; unsigned char alpha; char pad[3]; float ow,oh; };
struct Rect { float x,y,w,h; };
extern "C" float func_003EBE68(Obj *) throw();
extern "C" void func_003EBFD8(Vec *,float *,Vec *,Vec *,int,float,float,float) throw();
static inline float clamp(float x,float lo,float hi) { if(x<lo)x=lo; if(x>hi)x=hi; return x; }
static inline int clampi(int x) { if(x<0)x=0; if(x>255)x=255; return x; }
extern "C" int func_003EC060(Obj *o, Out *out, Rect *r) {
 float w=o->w, h=o->h;
 float hw=r->w*0.5f, hh=r->h*0.5f;
 float cx=r->x+hw, cy=r->y+hh;
 Vec center; center.x=w*0.5f; center.y=h*0.5f;
 int vertical=0;
 float scale=r->w/w;
 float sy=r->h/h;
 if(sy<scale) {scale=sy;vertical=1;}
 out->x=cx-center.x*scale;
 out->y=cy-center.y*scale;
 out->w=w*scale; out->h=h*scale;
 out->alpha=255; out->ow=w; out->oh=h;
 Vec pos=center;
 float zoom=scale;
 if(o->type==3) {
  Vec *focus=&o->focus, *lo=&o->lo, *hi=&o->hi;
  pos.x=w*(focus->x+1.0f)*0.5f;
  pos.y=h*(1.0f-focus->y)*0.5f;
  float d=hi->x-lo->x;
  if(vertical) d=hi->y-lo->y;
  d*=0.5f;
  if(d<0.5f) d=0.5f;
  if(d>1.0f) d=1.0f;
  float a=o->a*o->a;
  d+=(1.0f-d)*a;
  d-=o->b*0.199999988079071044921875f;
  if(d<0.5f) d=0.5f;
  if(d>1.0f) d=1.0f;
  zoom=scale/d;
 }
 if(pos.x*zoom<hw) pos.x=hw/zoom;
 if((w-pos.x)*zoom<hw) {
  pos.x=w-hw/zoom;
  if(pos.x*zoom<hw) pos.x=w*0.5f;
 }
 if(pos.y*zoom<hh) pos.y=hh/zoom;
 if((h-pos.y)*zoom<hh) {
  pos.y=h-hh/zoom;
  if(pos.y*zoom<hh) pos.y=h*0.5f;
 }
 if(!o->enabled) {pos=center;zoom=scale;}
 float t=(float)o->time/func_003EBE68(o);
 if(t<0.0f)t=0.0f;
 if(t>1.0f)t=1.0f;
 Vec result;
 float resultScale;
 func_003EBFD8(&result,&resultScale,&pos,&center,o->reverse,t,zoom,scale);
 out->x=cx-result.x*resultScale;
 out->y=cy-result.y*resultScale;
 out->w=w*resultScale; out->h=h*resultScale;
 int ret=1;
 switch(o->state) {
 case 0: out->alpha=clampi((int)((float)o->count/(float)o->fade*255.0f));break;
 case 1: case 2: out->alpha=255;break;
 case 3: out->alpha=clampi((int)((1.0f-(float)o->count/(float)o->fade)*255.0f));break;
 case 4: case 5: case 6: out->alpha=0;ret=0;break;
 }
 return ret;
}
