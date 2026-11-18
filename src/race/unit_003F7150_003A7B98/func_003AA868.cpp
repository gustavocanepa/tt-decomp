/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int unk; float x,y,z,lo,hi; char pad[0x18]; };
struct Table { char pad[0x30]; Node *base; };
struct Data { char pad[0xb0]; Table *table; };
struct Course { int unk; Data *data; };
struct Owner { char pad[0x80]; Course *course; };
struct Input { char pad[0x30]; float pos,unk,speed; int mode; };
struct Output { int flags,index; Node *node; float pos,target,speed,start,length,end,zero; };
struct Vec { float x,y,z; int index; };
extern "C" {
float RaceCourse__getCourseLength(Course*);
float func_0034B268(Course*,Vec*);
int func_0034BD58(Course*,Node**,int,int,float,float);
void func_003AA638(Output*,float) throw();
float func_003AA808(float,float,float,float) throw() __attribute__((const));
}
extern "C" int func_003AA868(Owner *self,Input *input,Output *output,int max,float duration) {
 int count=0;
 Course *course=self->course;
 float period=RaceCourse__getCourseLength(course);
 Table *table=course->data->table;
 {
 Node *nodes[max];
 float pos=input->pos;
 int mode=input->mode;
 float speed=input->speed;
 if(speed<0.1f) speed=0.1f;
 int i=0;
 int n=func_0034BD58(course,nodes,max,mode,pos,500.0f);
 if(n>0) {
 Output *out=output;
 for(;i<n;i++) {
  Node *node=nodes[i];
  Vec v;
  v.index=-1; v.x=node->x; v.y=node->y; v.z=node->z;
  float target=func_0034B268(course,&v);
  if(target<node->lo || node->hi<target) target=(node->lo+node->hi)*0.5f;
  out->flags=0;
  out->index=node-table->base;
  out->node=node;
  float p=func_003AA808(pos,node->lo,node->hi,period);
  out->target=target;
  out->pos=p;
  out->speed=speed;
  float start=(target-p)/speed;
  out->start=start;
  if(start<0.0f) start=0.0f;
  float actual=out->start;
  float tenth=duration/10.0f;
  float length=(node->hi-p)/speed-start;
  out->length=length;
  out->end=length+start;
  if(tenth<actual) out->flags=8;
  if(actual<duration-tenth) out->flags|=16;
  out->zero=0.0f;
  func_003AA638(out,duration);
  count++;
  out++;
  if(count>=max) break;
 }
 }
 }
 return count;
}
