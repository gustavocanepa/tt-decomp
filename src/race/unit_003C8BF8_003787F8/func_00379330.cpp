struct Vec2 {float x,y;};
struct __attribute__((packed)) Pair {unsigned long value;};
struct State {int kind;Pair position;int hits,index,edge,vertex;float distance;int flags;};
struct Polygon {int count;Vec2 points[0];};
struct Self {unsigned short opaque0,count;Polygon** polygons;};
extern "C" int func_00379768(Self*,const Vec2*);
extern "C" void func_00378830(State*);
extern "C" void func_00378858(State*,const Vec2*);
extern "C" float func_00378B90(Polygon*,int,const Vec2*,const Vec2*,State*);
extern "C" float func_00378FD8(Polygon*,int,const Vec2*,const Vec2*,State*,int);
extern "C" float func_00379200(Polygon*,int,const Vec2*,const Vec2*,State*,int);
extern "C" float func_00379330(Self* self,const Vec2* from,const Vec2* to,State* state){
 int inside=func_00379768(self,to);
 State backup=*state;
 float result=0;
 switch(state->kind){
 case 0:
  func_00378830(state);func_00378858(state,from);
  for(int i=0;i<self->count;++i)func_00378B90(self->polygons[i],i,from,to,state);
  if(!state->hits && inside)func_00378858(state,to);
  break;
 case 1:
  if(state->index>=0)result=func_00378FD8(self->polygons[state->index],state->index,from,to,state,inside);
  else if(inside)func_00378858(state,to);
  break;
 case 2:
  if(state->index>=0)result=func_00379200(self->polygons[state->index],state->index,from,to,state,inside);
  else if(inside)func_00378858(state,to);
  break;
 }
 return result;
}
