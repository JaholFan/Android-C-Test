#ifndef __LB_KEY_H__
#define __LB_KEY_H__

#define DEV_NAME "lbkey"

struct key_io_op_info {
	unsigned int io ;
	unsigned int op ;
	unsigned int param ;
	unsigned int param2 ;
};

#define	LBK_IOCTL_BASE	'L' // type

// NR
#define LBK_IOC_INIT       _IO(LBK_IOCTL_BASE, 1)  // type(8bits), nr(8bits), size(14bits)
#define LBK_IOC_DEINIT     _IO(LBK_IOCTL_BASE, 2)

 // GPIO Ctrl
#define GPIO_BASE    80
#define LBK_IOC_GPIO_DUMP_IO_STATUS       _IOW(LBK_IOCTL_BASE, GPIO_BASE + 0, int)
#define LBK_IOC_GPIO_SET_IO_FUNC          _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 1, struct key_io_op_info)
#define LBK_IOC_GPIO_GET_IO_FUNC          _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 2, struct key_io_op_info)
#define LBK_IOC_GPIO_SET_IO_DIR           _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 3, struct key_io_op_info)
#define LBK_IOC_GPIO_GET_IO_DIR           _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 4, struct key_io_op_info)

#define	LBK_IOC_GPIO_SET_IO_PULL_UP_ENB	  _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 5, struct key_io_op_info)
#define	LBK_IOC_GPIO_GET_IO_PULL_UP_ENB	  _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 6, struct key_io_op_info)	
#define LBK_IOC_GPIO_SET_IO_PULL_DN_ENB   _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 7, struct key_io_op_info)
#define LBK_IOC_GPIO_GET_IO_PULL_DN_ENB   _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 8, struct key_io_op_info)

#define LBK_IOC_GPIO_SET_IO_OUT_VALUE    _IOWR(LBK_IOCTL_BASE, GPIO_BASE +  9, struct key_io_op_info)
#define LBK_IOC_GPIO_GET_IO_OUT_VALUE    _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 10, struct key_io_op_info)
#define LBK_IOC_GPIO_GET_IO_IN_VALUE     _IOWR(LBK_IOCTL_BASE, GPIO_BASE + 11, struct key_io_op_info)

#define APP_WDT_BASE    200
#define LBK_IOC_APP_WDT_SET            _IOW(LBK_IOCTL_BASE, APP_WDT_BASE + 1, unsigned long)
#define LBK_IOC_APP_WDT_CANCEL         _IO(LBK_IOCTL_BASE, APP_WDT_BASE + 2)
#define LBK_IOC_APP_WDT_FEED           _IO(LBK_IOCTL_BASE, APP_WDT_BASE + 3)
#define LBK_IOC_APP_WDT_REQ_RESTART   _IO(LBK_IOCTL_BASE, APP_WDT_BASE + 4)

#define LBK_IOC_GPIO_SET_IO_DEBUG_PRINT       _IOW(LBK_IOCTL_BASE, APP_WDT_BASE + 10, int)


#endif /* __LB_KEY_H__ */