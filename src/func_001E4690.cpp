struct Rect{float x,y,w,h;Rect(){}Rect(float a,float b,float c,float d):x(a),y(b),w(c),h(d){}Rect(const Rect&r):x(r.x),y(r.y),w(r.w),h(r.h){}};
extern "C" int func_0020D718(void*),func_001E4ED0(void*);extern "C" const Rect*func_001E4F18(void*);extern "C" Rect func_001E4920(void*);
extern "C" float func_001E48A0(void*),func_001E48C0(void*),func_001E48E0(void*),func_001E4900(void*);extern "C" void func_001E4380(void*,float*,float*),func_001E2790(void*,void*);
static inline Rect intersect(const Rect&a,const Rect&b){float ax=a.x,bx=b.x;float x=bx<ax?ax:bx;float ay=a.y,by=b.y;float y=by<ay?ay:by;float ar=ax+a.w,br=b.x+b.w;float w=(br<ar?br:ar)-x;float ab=ay+a.h,bb=by+b.h;float h=(bb<ab?bb:ab)-y;if(w<=0||h<=0)w=h=0;return Rect(x,y,w,h);}
static inline bool nonempty(const Rect&r){return 0<r.w && 0<r.h;}
void func_001E4690(void*self,void*object){if(!func_0020D718(object))return;float left=0,top=0,right=0,bottom=0;
 if(func_001E4ED0(self)){const Rect*clip=func_001E4F18(self);Rect overlap=intersect(*clip,func_001E4920(self));if(nonempty(overlap)){left=overlap.x;top=overlap.y;right=left+overlap.w;bottom=top+overlap.h;}}
 else{left=func_001E48A0(self);top=func_001E48C0(self);right=left+func_001E48E0(self);bottom=top+func_001E4900(self);}
 float x,y;func_001E4380(self,&x,&y);if(left<=x&&x<right&&top<=y&&y<bottom)func_001E2790(self,object);
}
