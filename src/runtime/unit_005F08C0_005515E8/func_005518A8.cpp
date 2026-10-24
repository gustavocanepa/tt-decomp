struct Object;struct Record{Object*object;float key;};
typedef int(*Compare)(const Record*,const Record*);
template<class I>inline Record*value_type(const I&){return 0;}
template<class I>inline int*distance_type(const I&){return 0;}
extern "C" void func_00551BF8(Record*,Record*,Compare,Record*,int*);
extern "C" void func_00551B20(Record*,Record*,Compare);
extern "C" void func_00551CA0(Record*,int,int,Record,Compare);
static inline void make_heap(Record*first,Record*last,Compare compare){func_00551BF8(first,last,compare,value_type(first),distance_type(first));}
static inline void pop_inner(Record*first,Record*last,Record*result,Record value,Compare compare,int*){*result=*first;func_00551CA0(first,0,last-first,value,compare);}
extern "C" void func_005518A8(Record*first,Record*middle,Record*last,Record*,Compare compare){make_heap(first,middle,compare);for(Record*i=middle;i<last;++i)if(compare(i,first))pop_inner(first,middle,i,Record(*i),compare,distance_type(first));func_00551B20(first,middle,compare);}
