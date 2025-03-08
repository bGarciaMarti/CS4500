//
//  main.c
//  part2
//
//  Created by Secondary on 3/5/25.
//
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

int print_self_init_module(void) {
    
    struct task_struct *current = current_task();

    printk(KERN_INFO "Process name: %s\n", current->comm);
    
    printk(KERN_INFO "Process id/pid: %d\n", current->pid);
    
    printk(KERN_INFO "Process State: %ld", current->stat);
    /* switch(current->stat)
    {
      case -1 :
        printk("TASK IS UNABLE TO RUN\n");
        break;
      case 0 :
        printk("TASK_RUNNING\n");
        break;
    case 1:
        printk("TASK_INTERRUPTIBLE\n");
        break;
    case 2:
        printk("TASK_UNINTERRUPTIBLE\n");
        break;
    case 4:
        printk("TASK_STOPPED\n");
        break;
    case 8:
        printk("TASK_TRACED\n");
        break;
    case 16:
        printk("EXIT_ZOMBIE\n");
        break;
    case 32:
        printk("EXIT_DEAD\n");
        break;
        default :
        printk("TASK_BLOCKED\n");
        break;
    }
     */
	return 0;
} // end of print_self_init_module

void print_self_cleanup_module(void) {
    printk(KERN_INFO "Cleaning Up.\n");
} // end of print_self_cleanup_module

module_init(print_self_init_module);
module_exit(print_self_cleanup_module);

MODULE_LICENSE("GPL");
