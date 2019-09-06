#include <stdio.h>
#include <unistd.h>
#include <widgetlords.h>

int main(int argc, char** argv)
{
	vpe_3011b_init();
	
	sdafe_set_type(VPE_3011B_SDAFE_1, TYPE_1_MA);
	sdafe_set_type(VPE_3011B_SDAFE_2, TYPE_1_MA);
	sdafe_set_type(VPE_3011B_SDAFE_3, TYPE_1_MA);
	sdafe_set_type(VPE_3011B_SDAFE_4, TYPE_3_MA);
	
	uint8_t di;
	struct sdafe_reading an1, an2, an3, an4;
	
	while(1)
	{
		vpe_3011b_4ko_write_single(0, 1);
		vpe_3011b_4ko_write_single(1, 1);
		vpe_3011b_4ko_write_single(2, 0);
		vpe_3011b_4ko_write_single(3, 0);
		di = vpe_3011b_8di_read();
		printf("DI: %d\n", di);
		
		an1 = sdafe_read(VPE_3011B_SDAFE_1);
		an2 = sdafe_read(VPE_3011B_SDAFE_2);
		an3 = sdafe_read(VPE_3011B_SDAFE_3);
		an4 = sdafe_read(VPE_3011B_SDAFE_4);
		printf("SDAFE: %d %d\t %d %d\t %d %d\t %d %d\n", an1.status, an1.value, an2.status, an2.value, an3.status, an3.value, an4.status, an4.value);
		
		usleep(1000000);
		
		vpe_3011b_4ko_write_single(0, 0);
		vpe_3011b_4ko_write_single(1, 0);
		vpe_3011b_4ko_write_single(2, 1);
		vpe_3011b_4ko_write_single(3, 1);
		di = vpe_3011b_8di_read();
		printf("DI: %d\n", di);
		
		an1 = sdafe_read(VPE_3011B_SDAFE_1);
		an2 = sdafe_read(VPE_3011B_SDAFE_2);
		an3 = sdafe_read(VPE_3011B_SDAFE_3);
		an4 = sdafe_read(VPE_3011B_SDAFE_4);
		printf("SDAFE: %d %d\t %d %d\t %d %d\t %d %d\n", an1.status, an1.value, an2.status, an2.value, an3.status, an3.value, an4.status, an4.value);
		
		usleep(1000000);
	}
	
	return 0;
}
