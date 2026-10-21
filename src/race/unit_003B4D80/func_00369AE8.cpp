extern "C" void func_003697C8(void*,void*);
extern "C" int func_00369AE8(char*s){void*p=*(void**)(s+0x4844);if(!p)return 0;func_003697C8(s,p);*(int*)(s+0x4848)=1;*(void**)(s+0x4844)=0;return 1;}
