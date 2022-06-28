#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE "/dev/BSP"

int main() {
	int _open, _ioctl;
	int cmd, flag;
	
	_open = open(DEVICE, O_RDWR);
	if(_open < 0) {
		printf("Fail to open %s!\n", DEVICE);
		return 0;
	}
	
	printf("OK to open %s!\n\n", DEVICE);
	
	printf("0: Quit\n");
	printf("10: Stop thread1\n");
	printf("11: Start thread1\n");
	printf("12: Reset thread1\n");
	printf("20: Stop thread2\n");
	printf("21: Start thread2\n");
	printf("22: Reset thread2\n");
	printf("30: Stop All\n");
	printf("31: Start All\n");
	printf("32: Reset All\n\n");
	
	flag = 1;
	while(1) {
		if(flag == 0) break;
		printf("----------Input your order----------");
		scanf("%d", &cmd);
		switch(cmd) {
			case 0:
				flag = 0;
				break;
			case 10:
				_ioctl = ioctl(_open, 10, 0);
				printf("Stop thread1 !\n");
				break;
			case 11:
				_ioctl = ioctl(_open, 11, 0);
				if(_ioctl == -1) printf("Already started !\n");
				if(_ioctl == 0) printf("Start thread1 !\n");
break;
			case 12:
				_ioctl = ioctl(_open, 12, 0);
				printf("Reset thread1 !\n");
				break;
			case 20:
				_ioctl = ioctl(_open, 20, 0);
				printf("Stop thread2 !\n");
				break;
			case 21:
				_ioctl = ioctl(_open, 21, 0);
				if(_ioctl == -1) printf("Already started !\n");
				if(_ioctl == 0) printf("Start thread2 !\n");
				break;
			case 22:
				_ioctl = ioctl(_open, 22, 0);
				printf("Reset thread2 !\n");
				break;
			case 30:
				_ioctl = ioctl(_open, 30, 0);
				printf("Stop All !\n");
				break;
			case 31:
				_ioctl = ioctl(_open, 31, 0);
				if(_ioctl == -1) printf("Already started !\n");
				if(_ioctl == 1) printf("Start thread1, thread2 is already started !\n");
				if(_ioctl == 2) printf("Start thread2, thread1 is already started !\n");
				if(_ioctl == 0) printf("Start All !\n");
				break;
			case 32:
				_ioctl = ioctl(_open, 32, 0);
				printf("Reset All !\n");
				break;
			default:
				printf("ERROR ORDER !\n");
				break;
		}
	}
	
	close(_open);
	return 0;
}

