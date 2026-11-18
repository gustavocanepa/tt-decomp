extern "C" void func_004A4D68(void*),func_004A4DD8(void*);extern "C" void func_0052EED0(void*,void*);
struct It{void*p;};static inline void erase(void*p,It first,It last){func_0052EED0(p,first.p);}
extern "C" void func_001FEEA8(char*p,void*n){void*lock=p+284;func_004A4D68(lock);It a={n},b={n};erase(p+16,a,b);func_004A4DD8(lock);}
