extern "C" char D_005E93B8[];
extern "C" const char* MMovieSetting__makeMoviePath();
extern "C" unsigned func_004A8368(const char*);
extern "C" char* func_004F7A30(char*,const char*);
extern "C" int func_001D2508(char* dst,unsigned capacity,const char* name,const char* suffix) {
 if(!suffix)suffix=D_005E93B8;
 const char* prefix=MMovieSetting__makeMoviePath();
 unsigned n=func_004A8368(prefix);n+=func_004A8368(name);n+=func_004A8368(suffix);
 int r=0;
 if(n<capacity){*dst=0;func_004F7A30(dst,prefix);func_004F7A30(dst,name);func_004F7A30(dst,suffix);r=1;}
 return r;
}
