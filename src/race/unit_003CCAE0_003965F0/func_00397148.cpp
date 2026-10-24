/* compiler: ee-gcc2.96-nogcse */
struct Vec { float x,y,z; };
extern "C" float func_002E6150(void *,int,float);
extern "C" float func_002E62B8(void *,int,float);
extern "C" float func_002E6358(void *,int);
extern "C" int func_00397148(Vec *out,float *angle,void *object,int index,int side) {
    float x,y,z,a;
    if(side==0) {
        y=0.0f;
        x=func_002E6150(object,index,y);
        x=x-func_002E6358(object,index)*0.5f;
        z=func_002E62B8(object,index,y);
        a=0x1.921cacp+0f;
        out->x=x; out->y=y; out->z=z; *angle=a;
    } else {
        y=0.0f;
        x=func_002E6150(object,index,y);
        x=x+func_002E6358(object,index)*0.5f;
        z=func_002E62B8(object,index,y);
        a=0x1.2d958p+2f;
        out->x=x; out->y=y; out->z=z; *angle=a;
    }
}
