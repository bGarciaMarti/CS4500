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
    
    printk(KERN_INFO "Process State: ");
        process_state_name(current->__state);

    printk(KERN_INFO "The parent processes until init:");
    for (task = current; task != &init_task; task = task->parent) {
      printk(KERN_INFO "name: %s, id/pid: %s state: ", task->comm , task->pid);
        process_state_name(task->__state);
    }
    
	return 0;
} // end of print_self_init_module

void process_state_name (long silly_state) {
    if (silly_state == -1)
        return("TASK IS UNABLE TO RUN\n");
    else if (silly_state == 0)
        return("TASK_RUNNING\n");
    else if (silly_state == 1)
        return("TASK_INTERRUPTIBLE\n");
    else if (silly_state == 2)
        return("TASK_UNINTERRUPTIBLE\n");
    else if (silly_state == 4)
        return("TASK_STOPPED\n");
    else
        return("TASK_BLOCKED\n");
} // end of process_state_name

void print_self_cleanup_module(void) {
    printk(KERN_INFO "Cleaning Up.\n");
} // end of print_self_cleanup_module

module_init(print_self_init_module);
module_exit(print_self_cleanup_module);

MODULE_LICENSE("GPL");
