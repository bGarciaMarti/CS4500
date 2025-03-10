NAME OF PROJECT: Operating Systems Project 2
Kernel Modules and Processes
================

MEMBERS: Brenardo Garcia Marti
========

STATEMENT:
==========
I have neither given nor received unauthorized assistance on this work.

VIRTUAL MACHINE (VM) INFORMATION:
=================================

NAME OF VIRTUAL MACHINE (VM):
==========
BGarcia_funMachine

USENAME:  
==========
bdenny, Bren Garcia Marti

PASSWORD: 
========== 
1qaz2wsx3edc$RFV

Describe where the files can be found.
==========
Home/Desktop/Proj2

Describe each file and the purpose it serves.
==========


Provide any special instructions to access or run your program.
ROOT PASSWORD:
==============

PROBLEM DESCRIPTION AND REMEDIATION:
====================================
For the purposes of easier communication and screenshot inclusion, a Troubleshooting google doc was kept and used to record problems and remediation. Screenshots of all the results/outputs can be found on this document.
https://docs.google.com/document/d/1ubMQmqvIrXIotmqOoT8qYg8bLqUPCHkyElj1SV9Moa0/edit?usp=sharing

  PART 0: SET UP
  ==============
   the command line ``` $ sudo apt-get install gcc-12 vim``` was ran and installed.

  PART 1: Create a helloworld kernel module
  ===================
I've run into some trouble setting up the helloworld test kernel for Project 2. When I try to run the makefile, it gives this warning: "warning: the compiler differs from the one used to build the kernel." Running the command ```sudo apt install gcc-12``` updated the compiler. From there, the instructions were followed to completion without trouble.

  PART 2: Create a print_self kernel module
  ===========================
  1.When you load your module, which process is recognized as current?

the isnmod process is recognized as the current process

2. In newer kernels, what is it called and what do you see from your module’s output?

The process with an id/pid of 1 was named systemd

3. Do you notice something not working again [when working on displaying the state of a process]? From your module’s output, which state(s) are observed?

Yes, I did notice that the consol maked and ran, but didn't display the state. The consol stated that argument 2 has type ‘struct sched_statistics’. I returned to the instructions and reread Part 2’s step 3 instructions, where it states "Please see this kernel commit where task struc->state has been renamed as task struct->\_\_state." This resolved and the states observed were: insmod > sudo > sudo > bash > gnome-terminal- > systemd  

PART 3: Create a print_other kernel module
  ================================
