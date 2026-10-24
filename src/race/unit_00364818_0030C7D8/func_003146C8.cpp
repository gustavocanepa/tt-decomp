struct State{char p[2];unsigned char count;};struct O{char p[0x240];State state;char q[0x69];float values[256];};struct S{char p[16];O*owner;};
extern "C" int func_00310510(State*),func_0039F048(State*),func_00314640(S*,int);
inline int base(int i,const int&one,const int&small,const int&large){return (i^one)?small:large;}
extern "C" int func_003146C8(S*self,float limit){O*o=self->owner;State*s=&o->state;if(limit<0)return 0;if(func_00310510(s))return 1;if(func_0039F048(s))return 1;int count=s->count;int i=1;if(i<count){float*p=o->values;do{int offset=base(i,1,500,2000);float amount=(float)(func_00314640(self,i)-offset)*.10471975f / *p++;if(limit<amount)return i;count=s->count;++i;}while(i<count);}return count;}
