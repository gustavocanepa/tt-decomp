struct P{float x,y;};struct E{P*a,*b;int flag;};
extern "C" int func_0056AF98(E*a,E*b){
 if(a->a->y!=b->a->y)return a->a->y>b->a->y;
 if(a->a->x!=b->a->x)return a->a->x>b->a->x;
 float cross=(a->b->x-a->a->x)*(b->b->y-b->a->y)-(a->b->y-a->a->y)*(b->b->x-b->a->x);
 if(cross==0)return a->flag^1;
 return cross>0;
}
