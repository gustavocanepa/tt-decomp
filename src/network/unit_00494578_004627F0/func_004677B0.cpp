/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00469230(unsigned,int,int,int*);
extern "C" int func_004783E0(void*);
extern "C" int func_004782A8(int,void*);
extern "C" void func_00472C50(int,int,int,int,int,int,int,void*);
extern "C" void func_0046FB08(int);
extern "C" void func_00472628(void);
extern "C" void func_00471E18(int,int,int,int);
extern "C" void func_00472130(int,int);
extern "C" int func_004677B0(int psm,int w,int h,void *p) {
    int out;
    int size=func_00469230(psm,w,h,&out);
    int result=-1;
    if(size) {
        int n=func_004783E0(p);
        if(n>=0) goto setup;
        {
            n=func_004782A8(size,p);
            if(n<0) goto done;
            {
                func_00472C50(n,psm,out,0,0,w,h,p);
                func_0046FB08(1);
                func_00472628();
            }
        }
        if((n & 0x80000000)==0) {
setup:
            func_00471E18(0,n,psm,out);
            func_00472130(w,h);
        }
done:
        result=n;
    }
    return result;
}
