extern "C" void func_004A4D68(void*),func_004A4DD8(void*);extern "C" void func_0052EDE8(void*,void*);
struct It{void*p;};static inline void erase(void*p,It first,It last){func_0052EDE8(p,first.p);}
extern "C" void func_001FEE48(char*p,void*n){void*lock=p+284;func_004A4D68(lock);It a={n},b={n};erase(p+16,a,b);func_004A4DD8(lock);}
