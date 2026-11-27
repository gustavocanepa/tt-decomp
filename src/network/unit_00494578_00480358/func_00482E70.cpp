struct E{signed char id;char pad[7];};
struct S{char pad[0x85C];int active;};
struct Group{char pad[0x238];int count;E entries[1];};
extern "C" int func_00482E70(S*s,int id){Group*g=(Group*)((char*)s+(1-s->active)*0x41c);int limit=g->count;int i=0;if(limit>0){long count=limit;E*p=g->entries;do{if(p->id==id)return 1;++p;++i;}while(i<count);}return 0;}
