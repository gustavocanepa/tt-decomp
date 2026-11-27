struct Buf{unsigned char*data;unsigned size;inline Buf(unsigned char*p,unsigned n):data(p),size(n){}};
extern "C" Buf*func_00414870(Buf*),*func_004148C8(Buf*),*func_00414978(Buf*,const Buf*),*func_00414920(Buf*,const Buf*);
extern "C" int func_004149E8(const Buf*,const Buf*);
extern "C" void*func_004F6678(void*,int,unsigned),*func_004F64C4(void*,const void*,unsigned);
extern "C" Buf*func_00414B78(Buf*out,const Buf*numerator,const Buf*divisor,Buf*remainder){
 unsigned n=out->size;
 Buf a((unsigned char*)__builtin_alloca(n+1),n+1);func_004F6678(a.data,0,a.size);func_004F64C4(a.data,divisor->data,n);
 Buf coefficient((unsigned char*)__builtin_alloca(n+1),n+1);func_004F6678(coefficient.data,0,coefficient.size);coefficient.data[0]=1;
 Buf b((unsigned char*)__builtin_alloca(n+1),n+1);func_004F6678(b.data,0,b.size);func_004F64C4(b.data,numerator->data,n);
 Buf quotient((unsigned char*)__builtin_alloca(n+1),n+1);func_004F6678(quotient.data,0,quotient.size);
 while(func_004149E8(&a,&b)<0){func_00414870(&a);func_00414870(&coefficient);}
 while(func_004149E8(divisor,&b)<=0){
 while(func_004149E8(&b,&a)<0){func_004148C8(&a);func_004148C8(&coefficient);}
 func_00414978(&b,&a);func_00414920(&quotient,&coefficient);
 }
 func_004F64C4(out->data,quotient.data,out->size);
 func_004F64C4(remainder->data,b.data,remainder->size);
 return out;
}
