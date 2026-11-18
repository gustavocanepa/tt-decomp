inline bool less(int n,const int&limit){return n<limit;}
struct E{short priority,tag;int data;};union Index{int value;short h[2];};struct S{int a,b;E entries[256];unsigned char refs[28];Index count;};extern "C" void RaceEventQueue__remove(S*,int);
inline unsigned char*ref(int n,S*s){n+=(unsigned int)s;return (unsigned char*)(n+0x808);}
extern "C" void func_0036C908(S*s,int priority,int data,int tag){if(s->count.value==256){int index=0,max=-1,i=0;char*p=(char*)s;do{int v=((E*)(p+8))->priority;p+=8;if(max<v){max=v;index=i;}++i;}while(less(i,256));if(max<priority)return;RaceEventQueue__remove(s,index);}++*ref(priority,s);s->entries[s->count.value].priority=priority;s->entries[s->count.value].tag=tag;s->entries[s->count.value].data=data;++s->count.value;}
