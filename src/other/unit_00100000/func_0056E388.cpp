struct Job { char pad[0x3C]; char node[0x44]; int queued; };
struct Queue { char pad[0x4C]; char list[0x18]; char event[4]; };
extern "C" void func_004A4D68(Job *lock);
extern "C" void func_004A4DD8(Job *lock);
extern "C" void func_004AC838(void *list, void *node);
extern "C" void func_004AEB30(void *event);

extern "C" void func_0056E388(Queue *q, Job *job)
{
    func_004A4D68(job);
    job->queued = 1;
    func_004AC838(q->list, job->node);
    func_004A4DD8(job);
    func_004AEB30(q->event);
}
