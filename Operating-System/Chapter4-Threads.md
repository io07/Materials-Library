# Threads

-----

## Threads:
- A basic unit of CPU utilization; it comprises a thread ID, a program counter, a register set, and a stack. 
- Sharing code section, data section and other operating-system resouces with other threads which belong to the same process.
- benefits: a. Responsiveness || b. Resource sharing || c. Economy || d. Utilization of multiprocessor architectures

## Multithreading Models
- user threads / kernel threads.
- Three common relationship between user threads and kernel threads:
	1. many(u)-to-one(k). unable to run in paralled on multiprocessors.
	2. one(u)-to-one(k). can on mulproc but creation of kernel is costly, so number of threads is limited. 
	3. many(u)-to-many(k). user-level threads to a **smaller** or **equal** number of kernel threads, unlimited.

## Thread Libraries
In Linux we use the Pthreads.

functions:
- pthread_init()
- pthread_create()
- pthread_join()

## Threading Issues
- Threads using the fork(), does the new process duplicate all threads, or is the new process single-thread?, Linux provides two versions of fork():
	1. duplicates all threads.
	2. duplicates only the threads that invoked the fork() system call.

- Cancellation of a target thread may occur in two different scenarios:
	1. Asynchronous cancellation.
	2. Deferred cancellation.

- signals handling

- clone() system call in Linux to create a thread. However, Linux does not distinguish between processes and threads. Linux generally uses the term task -- rather process and thread. 

## Problems:
1. Provide examples of multithreading does not provide better performance than a single-threaded solution.
		
    Any kind of sequential program is not a good candidate to be threaded.

2. Under what circumstances does a multithreaded solution using multiple kernel threads provide better performance than a single-threaded solution on a single-processor system?

        When a kernel thread suffers a page fault, another Operating system concepts(Seventh edition) kernel thread can be switched in to use the interleaving time in a useful manner.
		
		A single-threaded process, on the other hand, will not be capable of performing useful work when a page fault takes place. Therefore, in scenarios where a program might suffer from frequent page faults or has to wait for other system events, a multi-threaded solution would perform better even on a single-processor system.

3. The threads of a multithreaded process share **heap memory** and **global variables**. Each thread has its sparate set of **register values** and a **separate stack**. 

4. mutithreaded solution using multiple user-level threads achieve better performance on a multiprocessor system than single-process system?
		
        The operating system sees only a single process and will not schedule the different threads of the process on separate processors.(one to one || many to many can??)

5. Consider amultiprocessor system and a multithreaded program written using the many-to-many threading model.	Let the number of user-level threads in the program be more than the number of processors in the system.Discuss the performance implications of the following scenarios.
	1. The number of kernel threads allocated to the program is less than the number of processors.
	2. The number of kernel threads allocated to the program is equal to the number of processors.
	3.  The number of kernel threads allocated to the program is greater than the number of processors but less than the number of userlevel threads.

		Answer:
			
			When the number of kernel threads is less than the number of processors, then some of the processors would remain idle since the scheduler maps only kernel threads to processors and not user-level threads to processors.
			
			When theOperating system concepts(Seventh edition) number of kernel threads is exactly equal to the number of processors, then it is possible that all of the processors might be utilized simultaneously. However, when a kernelthread blocks inside the kernel (due to a page fault or while invoking system calls), the corresponding processor would remain idle. 
			
			When there are more kernel threads than processors, a blocked kernel thread could be swapped out in favor of another kernel thread that is ready to execute, thereby increasing the utilization of the multiprocessor system.
