#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>    
#include <sys/ioctl.h> 
#include <stdlib.h>
#include "lb_key.h"

#define LBKEY_DEV  "/dev/lbkey"
int io_fd; 

static int pf_gpio_set_io_func(unsigned int io, unsigned int func)
{
        int ret ;
        struct key_io_op_info op_info = {io, func, 0, 0} ;
	
        ret = ioctl(io_fd, LBK_IOC_GPIO_SET_IO_FUNC, &op_info) ;
        if (ret < 0) {
                printf("[%s]: ioctl LBK_IOC_GPIO_SET_IO_FUNC failed!\n", __func__) ;
                return -1 ;
        }

        return 0 ;
}

static int pf_gpio_set_io_dir(unsigned int io, int dir)
{
        int ret ;
        struct key_io_op_info op_info = {io, dir, 0, 0} ;

        ret = ioctl(io_fd, LBK_IOC_GPIO_SET_IO_DIR, &op_info) ;
        if (ret < 0) {
                printf("[%s]: ioctl LBK_IOC_GPIO_SET_IO_DIR failed!\n", __func__) ;
                return -1 ;
        }

        return 0 ;
}

static int pf_gpio_set_out_value(unsigned int io, int val)
{
        int ret ;
        struct key_io_op_info op_info = {io, val, 0, 0} ;

        ret = ioctl(io_fd, LBK_IOC_GPIO_SET_IO_OUT_VALUE, &op_info) ;
        if (ret < 0) {
                printf("[%s]: ioctl LBK_IOC_GPIO_SET_IO_OUT_VALUE failed!\n", __func__) ;
                return -1 ;
        }

        return 0 ;
}

static int pf_gpio_get_in_value(unsigned int io, int * pval)
{
        int ret ;
        struct key_io_op_info op_info = {io, 0, 0, 0} ;

        ret = ioctl(io_fd, LBK_IOC_GPIO_GET_IO_IN_VALUE, &op_info) ;
        if (ret < 0) {
                printf("[%s]: ioctl LBK_IOC_GPIO_GET_IO_IN_VALUE failed!\n", __func__) ;
                return -1 ;
        }

        if (pval)
                *pval = op_info.param ;

        return 0 ;
}

enum {
    PAD_GPIO_A      = (0 * 32),
    PAD_GPIO_B      = (1 * 32),
    PAD_GPIO_C      = (2 * 32),
    PAD_GPIO_D      = (3 * 32),
    PAD_GPIO_E      = (4 * 32),
    PAD_GPIO_ALV    = (5 * 32),
};

int main(int argc, char *argv[])
{
    int ret;
	unsigned int io;
	int val;
	int tmp;
	
    io_fd = open(LBKEY_DEV, O_RDWR); //以读写方式进行打开
    if(io_fd < 0) {
        printf(LBKEY_DEV" open error \n");
        return -1;
    }
	
	val = atoi(argv[1]);

#if 1
    io = PAD_GPIO_D + 22;
	pf_gpio_set_io_func(io, 0); //funtion0
	pf_gpio_set_io_dir(io, 1);  //1:output,0:input
	pf_gpio_set_out_value(io, val) ;

    io = PAD_GPIO_D + 23;
	pf_gpio_set_io_func(io, 0); //funtion0
	pf_gpio_set_io_dir(io, 1);  //1:output,0:input
	pf_gpio_set_out_value(io, val) ;
#else
	pf_gpio_set_io_func(io, 0); //funtion0
	pf_gpio_set_io_dir(io, 0);  //1:output,0:input
	while(1){
		pf_gpio_get_in_value(io, &tmp);
		sleep(1);
		printf("input val == %d\n",tmp);
	}
#endif
	
    close(io_fd);

    return 0;
}










