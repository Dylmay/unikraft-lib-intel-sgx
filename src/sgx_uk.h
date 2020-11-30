//
// Alters header defines to allow compatability with Unikraft
// Created by Dylan Mayor on 30/11/2020.
//

#ifndef UNI_LIBSGX_DRIVER_SGX_UK_H

/* Header includes */
#include <uk/bitops.h>
#include <uk/refcount.h>
#include <uk/list.h>
#include <sys/types.h>
#include <uk/mutex.h>
//#include <uk/bitmap.h>
/* End of header includes */
////////////////////////////////////////////////////////////////////////////////
/* linux/asm.h definitions */
#ifndef _EXPAND_EXTABLE_HANDLE
# define _EXPAND_EXTABLE_HANDLE(x) #x
#endif

#ifndef _ASM_EXTABLE
# define _ASM_EXTABLE(from, to)						\
	" .pushsection \"__ex_table\",\"a\"\n"				\
	" .balign 4\n"							\
	" .long (" #from ") - .\n"					\
	" .long (" #to ") - .\n"					\
	" .long (" _EXPAND_EXTABLE_HANDLE(ex_handler_default) ") - .\n"	\
	" .popsection\n"
#endif
/* End of linux/asm.h definitions */
////////////////////////////////////////////////////////////////////////////////
/* uk/bitops.h name defines */
#ifndef BIT
# define BIT UK_BIT
#endif

#ifndef find_first_zero_bit
# define find_first_zero_bit uk_find_first_zero_bit
#endif

#ifndef find_first_bit
# define find_first_bit uk_find_first_bit
#endif

#ifndef set_bit
# define set_bit uk_set_bit
#endif

#ifndef clear_bit
# define clear_bit uk_clear_bit
#endif

#ifndef container_of
# define container_of __containerof
#endif
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

#ifndef u64
# define u64 __u64
#endif

#ifndef u32
# define u32 __u32
#endif

#ifndef u16
# define u16 __u16
#endif

#ifndef PAGE_SIZE
# define PAGE_SIZE __PAGE_SIZE
#endif

#ifndef PAGE_SHIFT
# define PAGE_SHIFT __PAGE_SHIFT
#endif

#ifndef PAGE_MASK
# define PAGE_MASK __PAGE_MASK
#endif

#ifndef phys_addr_t
# define phys_addr_t __phys_addr
#endif

#ifndef resource_size_t
# define resource_size_t phys_addr_t
#endif

#ifndef atomic_t
# define atomic_t __atomic
#endif

#ifndef ATOMIC_INIT
# define ATOMIC_INIT(i) {(i)}
#endif

/* End of Type declarations*/
////////////////////////////////////////////////////////////////////////////////
/* mutex defines */
#ifndef mutex
# define mutex uk_mutex
#endif

#ifndef mutex_lock
# define mutex_lock uk_mutex_lock
#endif

#ifndef mutex_unlock
# define mutex_unlock uk_mutex_unlock
#endif

#ifndef mutex_init
# define mutex_init uk_mutex_init
#endif
/* End of mutex defines */
////////////////////////////////////////////////////////////////////////////////
/* uk/list.h name defines */
#ifndef list_for_each_entry
# define list_for_each_entry uk_list_for_each_entry
#endif

#ifndef INIT_LIST_HEAD
# define INIT_LIST_HEAD UK_INIT_LIST_HEAD
#endif

#ifndef list_head
# define list_head uk_list_head
#endif

#ifndef LIST_HEAD
# define LIST_HEAD UK_LIST_HEAD
#endif

#ifndef list_splice
# define list_splice uk_list_splice
#endif

#ifndef list_empty
# define list_empty uk_list_empty
#endif

#ifndef list_first_entry
# define list_first_entry uk_list_first_entry
#endif

#ifndef list_move_tail
# define list_move_tail uk_list_move_tail
#endif

#ifndef list_for_each_entry_safe
# define list_for_each_entry_safe uk_list_for_each_entry_safe
#endif

#ifndef list_del
# define list_del uk_list_del
#endif

#ifndef list_del_init
# define list_del_init uk_list_del_init
#endif

#ifndef list_add_tail
# define list_add_tail uk_list_add_tail
#endif

#ifndef list_for_each_safe
# define list_for_each_safe uk_list_for_each_safe
#endif

#ifndef list_add
#define list_add uk_list_add
#endif
/* End of uk/list.h name defines*/
////////////////////////////////////////////////////////////////////////////////
/* pr_err name  defines */
#ifndef pr_err
# define pr_err uk_pr_err
#endif

#ifndef pr_warn
# define pr_warn uk_pr_warn
#endif

#ifndef pr_info
# define pr_info uk_pr_info
#endif

#ifndef BUG_ON
# define BUG_ON UK_BUGON
#endif
/* End of pr_err name defines */
////////////////////////////////////////////////////////////////////////////////
/* linux/kref.h struct kref replacement */
#ifndef _KREF_H_
struct kref {
	atomic_t refcount;
};
#endif
/* End of linux/kref.h struct replacement */
////////////////////////////////////////////////////////////////////////////////
/* End of kmap alternative */
#define UNI_LIBSGX_DRIVER_SGX_UK_H
#endif // UNI_LIBSGX_DRIVER_SGX_UK_H
