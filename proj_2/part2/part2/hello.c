#include <linux/module.h>
#include <linux/kernel.h>

int static_init_module(void){
	printk(KERN_INFO "Hello world!\n");
	return 0;
}

void static_cleanup_module(void){
	printk(KERN_INFO "Goodbye world!\n");
}

module_init(static_init_module);
module_exit(static_cleanup_module);

MODULE_LICENSE("GPL");
