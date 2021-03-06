#ifndef _NET_FLOWCACHE_H
#define _NET_FLOWCACHE_H

#include <linux/interrupt.h>
#include <linux/types.h>
#include <linux/timer.h>
#include <linux/notifier.h>

struct flow_cache_percpu {
	struct hlist_head		*hash_table;
	unsigned int			hash_count;
	u32				hash_rnd;
	int				hash_rnd_recalc;
	struct tasklet_struct		flush_tasklet;
};

struct flow_cache {
	u32				hash_shift;
	struct flow_cache_percpu __percpu *percpu;
	struct hlist_node		node;
	unsigned int			low_watermark;
	unsigned int			high_watermark;
	struct timer_list		rnd_timer;
};
#endif	/* _NET_FLOWCACHE_H */
