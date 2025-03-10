//
//  introcutions.c
//  part2
//
//  Created by Brenardo Garcia Marti on 3/5/25.
//
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

static int mypid = 9999;

module_param(mypid, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); //

int print_other_init_module(void) {

    struct task_struct *task; //synonym for structs
    
    printk(KERN_INFO "The given id/pid is %d\n", mypid);

    task = pid_task(find_vpid(mypid), PIDTYPE_PID); // pid_task(find_vpid(...), PIDTYPE_PID)
    if (task != NULL) {
        
        printk(KERN_INFO "Process name: %s\n", current->comm);
        
        printk(KERN_INFO "Process id/pid: %d\n", current->pid);
        
        if (current->__state == -1)
            printk(KERN_INFO "Process State: TASK IS UNABLE TO RUN\n");
        else if (current->__state == 0)
            printk(KERN_INFO "Process State: TASK_RUNNING\n");
        else if (current->__state == 1)
            printk(KERN_INFO "Process State: TASK_INTERRUPTIBLE\n");
        else if (current->__state == 2)
            printk(KERN_INFO "Process State: TASK_UNINTERRUPTIBLE\n");
        else if (current->__state == 4)
            printk(KERN_INFO "Process State: TASK_STOPPED\n");
        else
            printk(KERN_INFO "Process State: TASK_BLOCKED\n");

        printk(KERN_INFO "The parent processes until init:");
        for (task = current; task != &init_task; task = task->parent) {
            printk(KERN_INFO "parent process name: %s id/pid: %d state: %u\n", task->comm, task->pid, task->__state);
        }
    }
    else {
        printk(KERN_INFO "No process matches id/pid: %d \n", mypid);
    }
    
	return 0;
} // end of print_self_init_module

void print_other_cleanup_module(void) {
    printk(KERN_INFO "Clean Up.\n");
} // end of print_self_cleanup_module

module_init(print_other_init_module);
module_exit(print_other_cleanup_module);

MODULE_LICENSE("GPL");
