struct Object;struct Record{Object*object;float key;};
typedef int(*Compare)(const Record*,const Record*);
template<class I>inline Record*value_type(const I&){return 0;}
extern "C" void func_00551DA8(Record*,Record,Compare);
template<class I,class O>static inline O copy_inner(I first,I last,O result){for(int n=last-first;n>0;--n)*--result=*--last;return result;}
template<class I,class O>struct CopyDispatch{static O copy(I first,I last,O result){return copy_inner(first,last,result);}};
template<class I,class O>inline O copy_backward(I first,I last,O result){return CopyDispatch<I,O>::copy(first,last,result);}
static inline void linear_insert(Record*first,Record*last,Record*,Compare compare){Record value=*last;if(compare(&value,first)){copy_backward(first,last,last+1);*first=value;}else func_00551DA8(last,value,compare);}
extern "C" void func_005519A0(Record*first,Record*last,Compare compare){if(first==last)return;for(Record*i=first+1;i!=last;++i)linear_insert(first,i,value_type(first),compare);}
