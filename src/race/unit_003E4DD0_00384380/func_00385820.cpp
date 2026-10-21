inline float component(int index,float* p){unsigned int offset=index*4;offset+=(unsigned int)p;return *(float*)offset;}
extern "C" void func_00385820(float* output,float* a,float* b,int index,float value){
 float cb=component(index,b),ca=component(index,a);
 float inverse=1.0f/(cb-ca);
 float wa=(cb-value)*inverse;
 float wb=(value-ca)*inverse;
 if(index!=0)output[0]=a[0]*wa+b[0]*wb;else output[0]=value;
 if(index!=1)output[1]=a[1]*wa+b[1]*wb;else output[1]=value;
 if(index!=2)output[2]=a[2]*wa+b[2]*wb;else output[2]=value;
}
