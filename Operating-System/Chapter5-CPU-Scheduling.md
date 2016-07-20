# CPU Scheduling

----

## Basic Concepts
1. The objective of multiprogrammming is to have some process running at all times, to maximize CPU utilization.
2. CPU scheduler means the short-term scheduler.
3. CPU-Scheduler happens under four circumstances:(1,4 nonpreemptive; 2,3 preemptive)
	1. process switches  from running state to the waiting state
	2. ~~~ running to ready
	3. waiting to ready
	4. terminates

## Scheduling Criteria:
- CPU utilization
- Throughput: the number of processes that are completed per time unit.
- Turnaround time: the interval from the time of submisson of a process to the time of completion.
- Waiting time: Time in the waiting queue.
- Response time: the time from the submission of a request until the first response is produced.

## Scheduling Algorithms
1. First Come, First-Served Scheduling.
2. Shortest-Job-First Scheduling / Shortest-remaining-time-first.
3. Priority Scheduling. problems: indefinite blocking or starvation.
4. Round-Robin Scheduling, preemption is added, time quantum / time slice
5. Mutilevel Queue Scheduling

## Muliple-Processor Scheduling
- load sharing
- processor affinity, meanning that a process has an affinity for the processor on which it is currently running. many processor to one process.
- asymmetric multiprocessing | symmetric multiprocessing

## Linux Scheduling
- Symmetric multiprocessing (SMP) involves a symmetric multiprocessor system hardware and software architecture where two or more identical processors connect to a single, shared main memory, have full access to all I/O devices, and are controlled by a single operating system instance that treats all processors equally, reserving none for special purposes.
- Linux overhauled from Unix.
- preemptive, priority-based algorithm, twe priority ranges: real-time and nice.
- Linux assigns higher-priority tasks longer quanta and lower-priority tasks shorter time quanta.
- each processor is scheduling the highest-priority task from its own runqueue structure, when active array is empty, exchanged.
