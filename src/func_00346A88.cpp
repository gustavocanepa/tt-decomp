struct A{float x,y,z;};struct B{unsigned char flipx,flipy;short pad;float x,y,z;};struct E{char pad[44];};extern E D_00583F38[];
extern "C" void func_0034F500(E*,A*,float*,float*,float*,float*);
static inline E&entry(int i){return D_00583F38[i];}
extern "C" float func_00346A88(A*p,B*q,float*px,float*py,int i){float result=0,scale=0;func_0034F500(&entry(i),p,&scale,&result,px,py);float z=p->z/scale;float x=p->x/scale;int a=q->flipx!=0;int b=q->flipy!=0;q->y=p->y;q->z=z;q->x=x;if(z<0){if(x>=0)a=b;else b=a;}else{if(x>=0)a=b^1;else b=a^1;}q->flipy=b;q->flipx=a;if((unsigned char)a)*px=-*px;if(q->flipy)*py=-*py;return result;}
