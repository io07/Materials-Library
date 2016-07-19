# Chapter2 Operating-System Strucures

-----

1. Operating-System Services:
	- User interface / Program execution / IO operations / File-system manipulation / Error detection
	- Resource allocation / Accouting / Protection and security
2. Types of System Calls:
	- process control / file manipulation / device manipulation / information maintenance and communications.
3. example: printf() [user mode] --(standard C library)--> write() [kernel mode]

4. Virual Machines: A virtual machine is to abstract the hardware of a single computer(the CPU, memory ..) into several different execution environments.
	- Center: share the same hardware yet run several different execution environment (different operating systems)
	- A major difficulty with the virtual-machine approach involves disk systems. E.g: Three disk drives but wants to support seven virtual machines. **Solution**: virtual disks
	- **Implementation**: vm can only execute in only user mode --- v user mode / v kernel mode.
	- **Benefits**:
		1. protection of the various system resources.
		2. no direct sharing of resouces.
		3. perfect vehicle for operating-systems research and development.
5. Java Virtual Machine. (JVM)
	![Java execution steps](http://img.my.csdn.net/uploads/201212/21/1356070838_2499.png)
