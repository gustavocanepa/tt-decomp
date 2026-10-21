struct Object;struct Record{Object*object;float key;};
typedef int(*Compare)(const Record*,const Record*);
template<class I>inline Record*value_type(const I&){return 0;}
extern "C" void func_005518A8(Record*,Record*,Record*,Record*,Compare);
extern "C" Record*func_005517E0(Record*,Record*,Record,Compare);
static inline void partial_sort(Record*first,Record*middle,Record*last,Compare compare){func_005518A8(first,middle,last,value_type(first),compare);}
static inline const Record&median(const Record&a,const Record&b,const Record&c,Compare compare){
 if(compare(&a,&b)){if(compare(&b,&c))return b;else if(compare(&a,&c))return c;else return a;}
 else if(compare(&a,&c))return a;else if(compare(&b,&c))return c;else return b;
}
extern "C" void func_005515E8(Record*first,Record*last,Record*,int depth,Compare compare){
 while(last-first>16){if(depth==0){partial_sort(first,last,last,compare);return;}--depth;
 Record*cut=func_005517E0(first,last,Record(median(*first,*(first+(last-first)/2),*(last-1),compare)),compare);
 func_005515E8(cut,last,0,depth,compare);last=cut;}
}
