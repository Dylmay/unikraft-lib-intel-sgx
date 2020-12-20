//
// Alters header defines to allow compatability with Unikraft
// Created by Dylan Mayor on 30/11/2020.
//

#ifndef UNI_LIBSGX_DRIVER_SGX_UK_H

/* Header includes */
#include <uk/bitops.h>
#include <uk/refcount.h>
#include <uk/list.h>
#include <uk/radixtree.h>
#include <uk/kref.h>
#include <sys/types.h>
#include <uk/mutex.h>
#include <uk/tree.h>
/* End of header includes */
////////////////////////////////////////////////////////////////////////////////
/* linux/asm.h definitions */
# define _EXPAND_EXTABLE_HANDLE(x) #x

# define _ASM_EXTABLE(from, to)						\
	" .pushsection \"__ex_table\",\"a\"\n"				\
	" .balign 4\n"							\
	" .long (" #from ") - .\n"					\
	" .long (" #to ") - .\n"					\
	" .long (" _EXPAND_EXTABLE_HANDLE(ex_handler_default) ") - .\n"	\
	" .popsection\n"
/* End of linux/asm.h definitions */
////////////////////////////////////////////////////////////////////////////////
/* uk/bitops.h name defines */
# define BIT UK_BIT
# define find_first_zero_bit uk_find_first_zero_bit
# define find_first_bit uk_find_first_bit
# define set_bit uk_set_bit
# define clear_bit uk_clear_bit
# define container_of __containerof
/* End of uk/bitops.h name defines */
////////////////////////////////////////////////////////////////////////////////
/* Type declarations  */
#ifndef DIV_ROUND_UP
# define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#endif
#ifndef BITS_TO_LONGS
# define BITS_TO_LONGS(nr) DIV_ROUND_UP(nr, 8 * sizeof(long))
#endif
#ifndef DECLARE_BITMAP
# define DECLARE_BITMAP(name, bits) unsigned long name[BITS_TO_LONGS(bits)]
#endif
# define u64 __u64
# define u32 __u32
# define u16 __u16
# define PAGE_SIZE __PAGE_SIZE
# define PAGE_SHIFT __PAGE_SHIFT
# define PAGE_MASK __PAGE_MASK
# define phys_addr_t __phys_addr
# define resource_size_t phys_addr_t
#ifndef atomic_t
# define atomic_t __atomic
#endif
#ifndef ATOMIC_INIT
# define ATOMIC_INIT(i) {(i)}
#endif
/* End of Type declarations*/
////////////////////////////////////////////////////////////////////////////////
/* mutex defines */
# define mutex uk_mutex
# define mutex_lock uk_mutex_lock
# define mutex_unlock uk_mutex_unlock
# define mutex_init uk_mutex_init
/* End of mutex defines */
////////////////////////////////////////////////////////////////////////////////
/* Replace rwsem with normal semaphore. Semaphore defines */
/* End of semaphore defines */
////////////////////////////////////////////////////////////////////////////////
/* uk/list.h name defines */
# define list_for_each_entry uk_list_for_each_entry
# define INIT_LIST_HEAD UK_INIT_LIST_HEAD
# define list_head uk_list_head
# define LIST_HEAD UK_LIST_HEAD
# define list_splice uk_list_splice
# define list_empty uk_list_empty
# define list_first_entry uk_list_first_entry
# define list_move_tail uk_list_move_tail
# define list_for_each_entry_safe uk_list_for_each_entry_safe
# define list_del uk_list_del
# define list_del_init uk_list_del_init
# define list_add_tail uk_list_add_tail
# define list_for_each_safe uk_list_for_each_safe
#define list_add uk_list_add
/* End of uk/list.h name defines*/
////////////////////////////////////////////////////////////////////////////////
/* uk/radix.h name defines */
/* End of uk/radix.h name defines */
////////////////////////////////////////////////////////////////////////////////
/* uk/kref.h name defines */
#define kref uk_kref
#define kref_init uk_kref_init
#define kref_read uk_kref_read
#define kref_get uk_kref_get
#define kref_put uk_kref_put
#define kref_put_lock uk_kref_put_lock
#define kref_sub uk_kref_sub
#define kref_get_unless_zero uk_get_unless_zero
#define kref_put_mutex uk_kref_put_mutex
/* End of uk/kref.h name defines */
////////////////////////////////////////////////////////////////////////////////
/* pr_err name  defines */
#define pr_err uk_pr_err
#define pr_warn uk_pr_warn
#define pr_info uk_pr_info
#define BUG_ON UK_BUGON
/* End of pr_err name defines */
////////////////////////////////////////////////////////////////////////////////
/* End of kmap alternative */
#define UNI_LIBSGX_DRIVER_SGX_UK_H
#endif // UNI_LIBSGX_DRIVER_SGX_UK_H
