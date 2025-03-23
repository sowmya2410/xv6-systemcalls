int 
sys_getyear(void)
{
  return 2024;
}

int sys_sum(void) {
    int a, b;
    if (argint(0, &a) < 0 || argint(1, &b) < 0)
        return -1;
    return a + b;
}

int sys_diff(void) {
    int a, b;
    if (argint(0, &a) < 0 || argint(1, &b) < 0)
        return -1;
    return a - b;
}
int sys_product(void) {
    int a, b;
    if (argint(0, &a) < 0 || argint(1, &b) < 0)
        return -1;
    return a*b;
}

int sys_divide(void) {
    int a, b;
    if (argint(0, &a) < 0 || argint(1, &b) < 0)
        return -1;
    return a/b;
}

int sys_mod(void) {
    int a, b;
    if (argint(0, &a) < 0 || argint(1, &b) < 0)
        return -1;
    return a%b;
}
int
sys_getppid(void)
{
  return myproc()->parent->pid;
}

int sys_lettercount(void){

  char *str;
    if (argstr(0, &str) < 0)
        return -1;

    int count = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            count++;
        }
        str++;
    }
    return count;
}

int sys_procinfo(void) {
    struct proc *p = myproc();
    static char *states[] = {
        [UNUSED]    "unused",
        [EMBRYO]    "embryo",
        [SLEEPING]  "sleeping",
        [RUNNABLE]  "runnable",
        [RUNNING]   "running",
        [ZOMBIE]    "zombie"
    };
    cprintf("Process ID: %d\n", p->pid);
    cprintf("Parent Process ID: %d\n", p->parent ? p->parent->pid : -1);
    cprintf("Process State: %s\n", states[p->state]);
    cprintf("Process Name: %s\n", p->name);
    return 0;
}

int
sys_numprocs(void)
{
    int count = 0;
    struct proc *p = myproc();
   count = p->count;
    return count;
}
