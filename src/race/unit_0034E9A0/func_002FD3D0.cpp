struct Table {short count;char gap[2];const float* x;const float* y;};
extern "C" float func_002FD3D0(const Table* t,float v){
int last=t->count-1;float first=t->x[0],end=t->x[last];
if(v<=first)return t->y[0];
if(v>=end)return t->y[last];
unsigned high=last,low=0,index;
if(high-low>=4)do{index=(high+low)/2;
if(v<t->x[index])high=index;
else if(v==t->x[index])return t->y[index];
else low=index;}while(high-low>=4);
for(index=low;index<high;index++)if(v<t->x[index])break;
first=t->x[index-1];end=t->x[index];float lowy=t->y[index-1];
float offset=v-first;float highy=t->y[index];float span=end-first;float delta=highy-lowy;return lowy+delta*offset/span;
}
