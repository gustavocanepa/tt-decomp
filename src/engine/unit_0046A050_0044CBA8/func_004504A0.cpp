/* compiler: ee-gcc2.96-nogcse */
static inline void set(float *a, float x0,float x1,float x2,float x3,float x4,float x5,float x6,float x7,float x8,float x9,float x10,float x11,float x12,float x13,float x14,float x15) {
    a[0]=x0; a[4]=x1; a[8]=x2; a[12]=x3;
    a[1]=x4; a[5]=x5; a[9]=x6; a[13]=x7;
    a[2]=x8; a[6]=x9; a[10]=x10; a[14]=x11;
    a[3]=x12; a[7]=x13; a[11]=x14; a[15]=x15;
}
extern "C" void func_004504A0(float *a,const float *b) {
    float tmp[16];
    int i=0;
    int n=4;
    do {
        int j=0;
        float *dest = (float *)(i*4 + (int)tmp);
        int off=0;
        do {
            float sum=0.0f;
            const float *right = (const float *)(off*4 + (int)b);
            const float *left = (const float *)(i*4 + (int)a);
            int k=n;
            do {
                float r = *right;
                right++;
                float l = *left;
                left+=4;
                sum += l * r;
            } while (--k != 0);
            j++;
            *dest = sum;
            off += 4;
            dest += 4;
        } while (j<n);
        i++;
    } while (i<n);
    set(a,tmp[0],tmp[4],tmp[8],tmp[12],tmp[1],tmp[5],tmp[9],tmp[13],tmp[2],tmp[6],tmp[10],tmp[14],tmp[3],tmp[7],tmp[11],tmp[15]);
}
