#include <stdio.h>
#include <unistd.h>
#include <widgetlords.h>

int main(int argc, char** argv)
{
	vpe_2901a_init();
	
	sdafe_set_type(VPE_2901A_SDAFE_1, TYPE_1_MA);
	sdafe_set_type(VPE_2901A_SDAFE_2, TYPE_1_MA);
	
	uint8_t di1, di2;
	struct sdafe_reading an1, an2;
	
	while(1)
	{
		vpe_2901a_2ko_write_single(0, 1);
		vpe_2901a_2ko_write_single(1, 0);
		vpe_2901a_2ao_write_single(0, 2700);
		vpe_2901a_2ao_write_single(1, 0);
		di1 = vpe_2901a_2di_read_single(0);
		di2 = vpe_2901a_2di_read_single(1);
		printf("DI: %d %d\n", di1, di2);
		
		an1 = sdafe_read(VPE_2901A_SDAFE_1);
		an2 = sdafe_read(VPE_2901A_SDAFE_2);
		printf("SDAFE: %d %d\t %d %d\n", an1.status, an1.value, an2.status, an2.value);
		
		usleep(1000000);
		
		vpe_2901a_2ko_write_single(0, 0);
		vpe_2901a_2ko_write_single(1, 1);
		vpe_2901a_2ao_write_single(0, 0);
		vpe_2901a_2ao_write_single(1, 2700);
		di1 = vpe_2901a_2di_read_single(0);
		di2 = vpe_2901a_2di_read_single(1);
		printf("DI: %d %d\n", di1, di2);
		
		an1 = sdafe_read(VPE_2901A_SDAFE_1);
		an2 = sdafe_read(VPE_2901A_SDAFE_2);
		printf("SDAFE: %d %d\t %d %d\n", an1.status, an1.value, an2.status, an2.value);
		
		usleep(1000000);
	}
	
	return 0;
}
