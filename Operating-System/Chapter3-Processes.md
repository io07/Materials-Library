# Processes

----

A process is the unit of work in a moder time-sharing system.
A process is a program in execution.
Process in memory:
0 -----> max : text->data->heap->stack
Process state:
- New : The process is being created.
- Running : Instructions are being executed.
- Waiting : The process is waiting for some event to occur.
- Ready   : The process is waiting to be assigned to a processor.
- Terminated : The process has finished execution.
Diagram of states change:

new --admitted--> ready
ready --scheduler dispatch--> running
running --IO completion/interrupt-->ready
running --IO wait --> waiting
running --exit --> terminated

process control block, cotains many pieces of information associated with a specific process.

## Process Scheduling(process scheduler):
1. scheduling queues : job queue (consists of all processes in the system) / ready queue(contains pointers to the first and final PCBs in the list) / device queue
2. Linux representation: all active processes are represented using a **doubly linked list** of task_struct.
3. scheduler: select suitable process from the queues.
4. long-term scheduler:
	1. disk ---> memory
	2. much less frequently / minutes
	3. controls the **degree of multiprogramming**(the number of processes in memory).
	4.having more time to decide which process should be selected for execution.
5. short-term scheduler:
	1. memory--->cpu
	2. at lest once every 100 milliseconds
	3. must fast / high frequences
6. Medium-term scheduler: sometimes remove some processes from the memory. By swapping : swap out / swap in
7. Context Switch
	interrrupts cause the operating system to change a CPU from its current task and to run a kernel routine
	state save / state restore
## Operations on Processes
- parent, children forming a tree of processes, unique flag pid
- When a process creates a subprocess, that process's resources can be obtained from a. os b. parent
- Two possibilities in terms of execution: a. parent exe concurrently with its children / b. wait until the children terminated.
- Two possibilities of address space: a. duplicate b. new
- fork() [process creation]: 
	1. the new process consists of a copy of the address space
	2. fork()调用的奇妙之处在于他仅仅被调用一次，却能够返回两次，又三种不同的返回值: a. 父进程返回儿子的id b. 子进程返回0 c. 出现错误返回负值
	3.  一个进程调用fork（）函数后，系统先给新的进程分配资源，例如存储数据和代码的空间。然后把原来的进程的所有值都复制到新的新进程中，只有少数值与原来的进程的值不同。相当于克隆了一个自己。
- Process Termination : exit() / cascading termination : parent terminate, children terminate too.
- e.g.1:

```C++
    /* 
     *  fork_test.c 
     *  version 1 
     *  Created on: 2010-5-29 
     *      Author: wangth 
     */  
    #include <unistd.h>  
    #include <stdio.h>   
    int main ()   
    {   
        pid_t fpid; //fpid表示fork函数返回的值  
        int count=0;  
        fpid=fork();   
        if (fpid < 0)   
            printf("error in fork!");   
        else if (fpid == 0) {  
            printf("i am the child process, my process id is %d/n",getpid());   
            printf("我是爹的儿子/n");//对某些人来说中文看着更直白。  
            count++;  
        }  
        else {  
            printf("i am the parent process, my process id is %d/n",getpid());   
            printf("我是孩子他爹/n");  
            count++;  
        }  
        printf("统计结果是: %d/n",count);  
        return 0;  
    }  

```
- e.g.2:

```C++

    /* 
     *  fork_test.c 
     *  version 3 
     *  Created on: 2010-5-29 
     *      Author: wangth 
     */  
    #include <unistd.h>  
    #include <stdio.h>  
    int main(void)  
    {  
       int i=0;  
       for(i=0;i<3;i++){  
           pid_t fpid=fork();  
           if(fpid==0)  
               printf("son/n");  
           else  
               printf("father/n");  
       }  
       return 0;  
      
    }  

```

The in the above programe, the printf is executed for 14 times and we can have the conclusion that if the loop number is n, then printf is executed for 2^(n+1) - 2 times. This can be designed into a problem ha~

## Interprocess Communication
- Any process that does not share data with any other process is independent or is cooperating.
- Two models of interprocess communication: shared memory / message passing.


