struct Mat {float v[16];};
struct Quat {float x,y,z,w;};
struct State {int hasAngle;float angle;int hasTransform;float a,b;Mat matrix;int hasOther;float c,d;};
extern "C" void func_00451470(Quat*,const Mat*);
extern "C" void func_004534F0(Quat*,const Quat*,const Quat*,float);
extern "C" void func_00451270(const Quat*,Mat*,float,float,float);
extern "C" void func_0036F388(State*out,const State*left,const State*right,float t){
 out->hasAngle=left->hasAngle && right->hasAngle;
 if(out->hasAngle)out->angle=left->angle*(1-t)+right->angle*t;
 out->hasTransform=left->hasTransform && right->hasTransform;
 if(out->hasTransform){
 Quat q,ql,qr;
 float first=left->a;
 float inv=1-t;
 Quat*pql=&ql;Quat*pqr=&qr;
 const Mat*ml=&left->matrix;const Mat*mr=&right->matrix;Mat*mo=&out->matrix;
 out->a=first*inv+right->a*t;
 out->b=left->b*inv+right->b*t;
 func_00451470(pql,ml);func_00451470(pqr,mr);
 func_004534F0(&q,pql,pqr,t);
 func_00451270(&q,mo,ml->v[12]*inv+mr->v[12]*t,ml->v[13]*inv+mr->v[13]*t,ml->v[14]*inv+mr->v[14]*t);
 }
 out->hasOther=left->hasOther && right->hasOther;
 if(out->hasOther){out->c=left->c*(1-t)+right->c*t;out->d=left->d*(1-t)+right->d*t;}
}
