/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_003D23C0(float) throw();
extern "C" int func_003E6F48(float);
static inline int direction(float x){if(x>=0.0f)return 0;return 1;}
static inline int get_mode(int *mode){return *mode;}
extern "C" void func_003D25D8(int side,int active,float angle,float delta,float speed,float amount,float*out,float*target,int*flag,float*current,int unused6,int*other,int u8,int u9,int u10,int u11,int u12,int u13,int u14,int u15,int*state,int*mode){
 int saved_active=active;float saved_angle=angle;
 int sign=direction(delta);float margin=0;
 if(side==sign)margin=0x1.657182p-2f;
 float lower=-0x1.43eedep+1f;if(side!=0)lower=0x1.38c352p-1f;
 float upper=-0x1.38c352p-1f;if(side!=0)upper=0x1.43eedep+1f;
 float low=lower-margin,high=upper+margin;
 int again;
 do{again=0;switch(*state){
 case 0:
 *current+=delta;
 if(saved_active){
 if(*current<=low && (delta<0 || *mode==0))*state=1;
 else if(high<=*current && (delta>0 || *mode==0))*state=1;
 }
 {float v=*current;*out=v;*target=v;}*flag=0;break;
 case 1:
 if((unsigned)(*mode-2)<2)*state=0;else if(get_mode(mode)==5 || get_mode(mode)==6)*state=0;else *state=2;
 again=1;break;
 case 2:{
 float base=saved_angle-0x1.2d97c6p+1f;float quarter=0x1.921fb4p+0f;float period=0x1.921fb4p+2f;float start=-0x1.921fb4p+1f;
 for(int i=0;i<8;i++){
 float a=base+(float)(i%4)*quarter;
 a-=start;
 a-=(float)func_003E6F48(a/period)*period;
 a+=start;
 if(i<4){if(lower<=a){if(a<=upper)goto found;}}
 else{if(low<=a){if(a<=high)goto found;}}
 continue;
 found: *target=a;break;
 }
 int passed=0;
 if(*current<*target){*current+=func_003D23C0(amount)*speed;if(*target<*current)passed=1;}
 else{*current-=func_003D23C0(amount)*speed;if(*current<*target)passed=1;}
 *out=*current;
 if(passed){float v=*target;*out=v;*current=v;*flag=0;*other=0;*state=0;*mode=0;}
 break;}
 default:break;
 }}while(again);
}
