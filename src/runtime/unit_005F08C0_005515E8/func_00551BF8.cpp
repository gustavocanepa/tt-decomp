struct Object;struct Record{Object*object;float key;};
typedef int(*Compare)(const Record*,const Record*);
extern "C" void func_00551CA0(Record*,int,int,Record,Compare);
extern "C" void func_00551BF8(Record*first,Record*last,Compare compare,Record*,int*){
 if(last-first<2)return;
 int length=last-first;int parent=(length-2)/2;
 while(true){func_00551CA0(first,parent,length,Record(first[parent]),compare);if(parent==0)return;--parent;}
}
