extern signed char D_005865A0[8][6];extern "C" int func_004369F0(void*,int);
extern "C" int func_004389E0(void*s,unsigned n){if(n>=8)n=6;int v=D_005865A0[n][0];int i=0;if(v!=-1){signed char*p=D_005865A0[n];do{if(func_004369F0(s,v))return v;++i;++p;if(i>=6)break;v=*p;}while(v!=-1);}return -1;}
