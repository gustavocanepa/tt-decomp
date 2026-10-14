extern "C" float func_004A5A68(float);extern float D_005839D0[],D_005839F0[];
static inline float absf(float x){float y;asm("abs.s %0,%1":"=f"(y):"f"(x));return y;}
extern "C" float func_00317630(float x,float y){float ax=absf(x),ay=absf(y);int flags=0;float ratio;if(ax<ay){flags=4;if(ay==0.0f)return 0.0f;ratio=ax/ay;}else{if(ax==0.0f)return 0.0f;ratio=ay/ax;}if(x<0.0f)flags|=1;if(y<0.0f)flags|=2;float angle=func_004A5A68(ratio);angle=angle*180.0f/3.14159265f;return D_005839D0[flags]+D_005839F0[flags]*angle;}
