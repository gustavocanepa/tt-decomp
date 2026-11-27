/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row {float *p;Row(float*q):p(q){}Row(const Row&r):p(r.p){}float&operator[](int n){return p[n*4];}};
struct Mat {float v[16];Row operator[](int n){return Row(v+n);}};
extern "C" void func_003E9228(Mat*in,Mat*out){
 (*out)[0][0]=(*in)[0][0];
 (*out)[0][1]=(*in)[1][0];
 (*out)[0][2]=(*in)[2][0];
 (*out)[0][3]=-(*in)[0][0]*(*in)[0][3]-(*in)[1][0]*(*in)[1][3]-(*in)[2][0]*(*in)[2][3];
 (*out)[1][0]=(*in)[0][1];
 (*out)[1][1]=(*in)[1][1];
 (*out)[1][2]=(*in)[2][1];
 (*out)[1][3]=-(*in)[0][1]*(*in)[0][3]-(*in)[1][1]*(*in)[1][3]-(*in)[2][1]*(*in)[2][3];
 (*out)[2][0]=(*in)[0][2];
 (*out)[2][1]=(*in)[1][2];
 (*out)[2][2]=(*in)[2][2];
 (*out)[2][3]=-(*in)[0][2]*(*in)[0][3]-(*in)[1][2]*(*in)[1][3]-(*in)[2][2]*(*in)[2][3];
 out->v[3]=0;out->v[7]=0;out->v[11]=0;out->v[15]=1;
}
