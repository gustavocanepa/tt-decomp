static inline float &at(float*p,int i){p+=i;return *p;}
extern "C" void func_004542D0(float*d,int i,float*a,float*b){
 i*=4;
 at(d,i)=at(a,i)/at(b,i);
 ++i; at(d,i)=at(a,i)/at(b,i);
 ++i; at(d,i)=at(a,i)/at(b,i);
 ++i; at(d,i)=at(a,i)/at(b,i);
}
