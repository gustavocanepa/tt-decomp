struct R { char pad[62];unsigned char count; };struct V { short delta,index;void *fn; };struct S { char pad[0x134];V *table;char member[1]; };struct G { char pad[0xC4];int count;char pad2[16];char member[1]; };
extern "C" G *D_005857DC;
extern "C" void func_00370368(S *,void *);
extern "C" long long func_0040FC00(const char*);
extern "C" void func_0037B0D0(void *,void *);
static inline R *get(S *s) { V *v=(V*)((char*)s->table+0x98);return ((R*(*)(void*))v->fn)((char*)s+v->delta); }
static inline void set(S *s,int off,int n) { V *v=(V*)((char*)s->table+off);((void(*)(void*,int))v->fn)((char*)s+v->delta,n); }
static inline void setKey(S*s,long long key){V*v=(V*)((char*)s->table+0x20);((void(*)(void*,long long))v->fn)((char*)s+v->delta,key);}
extern "C" void func_0010DCB8(S *s) { func_00370368(s,(char*)D_005857DC+0x44);int n=D_005857DC->count;if(get(s)->count<n)n=get(s)->count;set(s,0x50,n);setKey(s,func_0040FC00((char*)D_005857DC+4));func_0037B0D0(s->member,(char*)D_005857DC+0xE0); }
