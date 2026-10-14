struct Method {short offset;short pad;void(*call)(void*,int,int);};
struct VTable {char gap[0x38];Method position,size,color;};
struct Widget {unsigned flags;char gap[0x10];VTable* table;float a,b;int id;};
struct Slot {char gap[0x50];Widget widget;char gap74[0x30];float time;char gapa8[0x14];int state;char gapc0[0x90];};
extern "C" void RaceMessageDisplay__setFont(Widget*,void*,int);
extern "C" void RaceMessageDisplay__setMessage(Widget*,const char*,float,float);
static inline float maximum(float a,float b){float r;__asm__("max.s %0,%1,%2":"=f"(r):"f"(a),"f"(b));return r;}
extern "C" void RaceEventDisplay__addEvent(char* self,const char* text,float delta,float value,float a,float b){
char* scan=self;for(int i=0;i<8;i++,scan+=0x150){
Widget* w=(Widget*)(scan+0x50);int available=0;
if(*(int*)(scan+0xbc)==2 && *(float*)(scan+0xa4)<=0)available=1;
if(available){w->a=a;w->b=b;w->flags=(w->flags&~255U)|1;w->id=*(int*)(self+0x20);RaceMessageDisplay__setFont(w,self+0x30,*(int*)(self+0x2c));
Method* m=&w->table->position;int x=*(short*)(self+4)+*(int*)(self+0x18);int y=*(short*)(self+6)+*(int*)(self+0x1c);m->call((char*)w+m->offset,x,y);
Method* size=&w->table->size;size->call((char*)w+size->offset,*(short*)(self+8),*(short*)(self+10));
Method* color=&w->table->color;color->call((char*)w+color->offset,(unsigned char)self[1],(unsigned char)self[2]);
if(value==0){value=*(float*)(self+0x28);*(float*)(self+0x28)=value+delta;}
else{value=maximum(value,0);value+=*(float*)(self+0x24);*(float*)(self+0x28)=maximum(*(float*)(self+0x28),value+delta);}
*(float*)(self+0x24)=value;RaceMessageDisplay__setMessage(w,text,delta,value);goto done;
}}
done:*(int*)(self+0x18)=0;*(int*)(self+0x1c)=0;
}
