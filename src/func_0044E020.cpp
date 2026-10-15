extern "C" void func_004A6328(float*,float*,float);
static inline float &elem(float*p,const int&i){return *(float*)((char*)p+i);}
static inline const float &elem(const float*p,const int&i){return *(const float*)((const char*)p+i);}
extern "C" void func_0044E020(float*out,const float*v,float angle){float s,c;func_004A6328(&s,&c,angle*0.5f);out[0]=v[0]*s;elem(out,4)=elem(v,4)*s;elem(out,8)=elem(v,8)*s;out[3]=c;}
