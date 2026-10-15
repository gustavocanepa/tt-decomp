/* compiler: ee-gcc2.96-nogcse */
extern "C" void func_004505A8(float *out, const float *a, const float *b) {
    int i=0;
    int n=4;
    do {
        int j=0;
        float *dest = (float *)(i*4 + (int)out);
        int off=0;
        do {
            float sum=0.0f;
            const float *right = (const float *)(off*4 + (int)b);
            const float *left = (const float *)(i*4 + (int)a);
            int k=n;
            do {
                float l = *left;
                left+=4;
                float r = *right;
                right++;
                sum += l * r;
            } while (--k != 0);
            j++;
            *dest = sum;
            off += 4;
            dest += 4;
        } while (j<n);
        i++;
    } while (i<n);
}
