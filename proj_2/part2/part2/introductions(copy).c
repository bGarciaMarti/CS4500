//
//  introcutions.c
//  part2
//
//  Created by Brenardo Garcia Marti on 3/5/25.
//
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

int print_self_init_module(void) {

    struct task_struct *task; //synonym for structs

    printk(KERN_INFO "Process name: %s\n", current->comm);
    
    printk(KERN_INFO "Process id/pid: %d\n", current->pid);
    
    if (current->__state == -1)
        printk("Process State: TASK IS UNABLE TO RUN\n");
    else if (current->__state == 0)
        printk("Process State: TASK_RUNNING\n");
    else if (current->__state == 1)
        printk("Process State: TASK_INTERRUPTIBLE\n");
    else if (current->__state == 2)
        printk("Process State: TASK_UNINTERRUPTIBLE\n");
    else if (current->__state == 4)
        printk("Process State: TASK_STOPPED\n");
    else
        printk("Process State: TASK_BLOCKED\n");

    printk("The parent processes until init:");
    for (task = current; task != &init_task; task = task->parent) {
        printk(KERN_INFO "parent process name: %s id/pid: %d state: %u\n", task->comm, task->pid, task->__state);
    }
    
	return 0;
} // end of print_self_init_module

void print_self_cleanup_module(void) {
    printk(KERN_INFO "Cleaning Up.\n");
} // end of print_self_cleanup_module

module_init(print_self_init_module);
module_exit(print_self_cleanup_module);

MODULE_LICENSE("GPL");
