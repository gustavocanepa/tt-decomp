struct Matrix{float v[16];}; struct State{int words[15];};struct Render{int word,flag;};struct Resource;
struct Entry{short words[6];short index,offset,other,last;};struct Record{short words[4];short a,b;Resource*resource;};
struct Tables{char gap[144];Entry*entries;int unknown;Matrix*matrices;char gap2[20];Record*records;};
struct Obj{char gap[0x6e14];Render*render;unsigned char color[8];Tables*tables;};struct Input{unsigned short kind;short index,a,b;int word;};
extern "C" void func_00444B70(unsigned*,const void*,const void*,float),func_00444E10(Matrix*,const Matrix*,const Matrix*,float),func_00439EC8(Render*,unsigned),func_0043F740(Matrix*,int,int,float),func_0043F780(Obj*,Resource*,Matrix*),func_00104868(State*,int),func_0043A640(State*,Resource*,Resource*,float),func_0043A2C8(Render*,State*),func_0043A2E8(Render*,int),func_00478C98(int);
extern "C" unsigned func_00445370(const unsigned char*,const unsigned char*);
extern "C" State*func_0043A338(State*,Render*,int,int,int,int),*func_00104960(State*,const State*);
inline Record* record(Tables*t,int index){return &t->records[index];}
extern "C" void func_0043FA18(Input*in,Obj*self,State*out,float t){unsigned color;Matrix m;State temp;
 if(in->kind==0){func_00444B70(&color,&in->a,&in->word,t);func_00439EC8(self->render,func_00445370(self->color,(unsigned char*)&color));}
 else if((unsigned short)(in->kind-1)<2){Entry*entry=&self->tables->entries[in->index];Record*r=&self->tables->records[entry->index];func_00444E10(&m,&self->tables->matrices[in->a],&self->tables->matrices[in->b],t);if(in->kind==1){func_0043F740(&m,entry->offset,r->b,t);func_0043F780(self,r->resource,&m);}else{func_0043A338(&temp,self->render,r->a,r->b,0,0);func_00104960(out,&temp);func_00104868(&temp,2);Resource*other=record(self->tables,entry->other)->resource;func_0043A640(out,r->resource,other,t);func_0043A2C8(self->render,out);func_0043F780(self,0,&m);}func_0043A2E8(self->render,1);return;}
 else if((unsigned short)(in->kind-3)<2){func_00444E10(&m,&self->tables->matrices[in->a],&self->tables->matrices[in->b],t);Resource*selected=record(self->tables,in->index)->resource;func_0043F780(self,selected,&m);if(in->kind==3){func_0043A2E8(self->render,2);return;}func_0043A2E8(self->render,1);return;}
 Render*r=self->render;func_00478C98(2);r->flag=0;
}
