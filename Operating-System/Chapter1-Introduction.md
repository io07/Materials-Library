# Chapter1-Introduction

---

1. computer can be divided into four components:
    - hardware
    - operating system
    - application programs
    - users
2. bootstrap program / interrupt / system call[software interrupt] / volatile storage / nonvolatile storage
3. computer programes must be in main memory and main memory is the only large stroage area that the processor can access directly.
4. I/O structure, direct memory access(DMA)
5. OS genres:
    - **Single-Processor Systems**
    - **Multiprocessor Systems**: asymmetric multio [specific tasks] / symmetric multio[many tasks]
    -  **clustered system** : together multiple CPUs to accomplish computational work and is used to provide high-availability service. If the monitored machine fails, the monitoring machine can take ownership of its storage and restart the applications.
    -  **distributed System** is a collection of physically separate, possibly heterogeneous computer systems that are networked to provide the users with access to the various resources that the system maintains.
    -  **Real-Time Embedded Systems**, they tend to have very specific tasks.
    -  **Handheld Systems**: include personal digital assitants.
6. Modern operating systems are **interrupt driven**, **trap** is a software-generated interrupt caused either by an error.
7. Two separate modes of operation: **user mode** and **kernel mode** (also called supervisor mode, system mode or privileged mode). mode bit (0/1)
8. **Summary**:
