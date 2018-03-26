[CCode (cheader_filename = "widgetlords.h")]
namespace WidgetLords
{
	public const uint8 DIR_RS485;
	
	namespace PiSpi
	{	
		[CCode (cname = "pi_spi_init")]
		void init();
		
		[CCode (cname = "pi_spi_2ao_write_single")]
		void write_single_2ao(uint8 channel, uint16 counts, bool optional = false);
		
		[CCode (cname = "pi_spi_8ai_read_single")]
		void read_single_8ai(uint8 channel, bool optional = false);
		
		[CCode (cname = "pi_spi_8di_read")]
		uint8 read_8di(uint8 address, bool optional = false);
		
		[CCode (cname = "pi_spi_8di_read_single")]
		uint8 read_single_8di(uint8 address, uint8 channel, bool optional = false);
		
		[CCode (cname = "pi_spi_8di_init")]
		void init_8di(uint8 address, bool optional = false);

		[CCode (cname = "pi_spi_8ko_write")]
		void write_8ko(uint8 data, bool optional = false);
		
		[CCode (cname = "pi_spi_8ko_write_single")]
		void write_single_8ko(uint8 channel, uint8 data, bool optional = false);
	}
	
	namespace PiSpiDin
	{
		[CCode (cname = "enum chip_enable", cprefix = "", has_type_id = false)]
		public enum ChipEnable
		{
		  CE0,
		  CE1,
		  CE2,
		  CE3,
		  CE4
		}
		
		[CCode (cname = "pi_spi_din_init")]
		void init();
		
		[CCode (cname = "pi_spi_din_4ao_init")]
		void init_4ao();
		
		[CCode (cname = "pi_spi_din_4ao_write_single")]
		void write_single_4ao(uint8 channel, uint16 counts);

		[CCode (cname = "pi_spi_din_8ai_read_single")]
		uint16 read_single_8ai(ChipEnable ce, uint8 channel);

		[CCode (cname = "pi_spi_din_8di_read")]
		uint8 read_8di(ChipEnable ce, uint8 address);
		
		[CCode (cname = "pi_spi_din_8di_read_single")]
		uint8 read_single_8di(ChipEnable ce, uint8 address, uint8 channel);
		
		[CCode (cname = "pi_spi_din_8di_init")]
		void init_8di(ChipEnable ce, uint8 address);

		[CCode (cname = "pi_spi_din_4ko_write")]
		void write_4ko(ChipEnable ce, uint8 address, uint8 state);
		
		[CCode (cname = "pi_spi_din_4ko_write_single")]
		void write_single_4ko(ChipEnable ce, uint8 address, uint8 channel, uint8 state);
		
		[CCode (cname = "pi_spi_din_4ko_init")]
		void init_4ko(ChipEnable ce, uint8 address);

		[CCode (cname = "vpe_2901a_init")]
		void vpe_2901a_init();
		
		[CCode (cname = "vpe_2901a_2ao_write_single")]
		void vpe_2901a_2ao_write_single(uint8 channel, uint16 counts);
		
		[CCode (cname = "vpe_2901a_2ko_write_single")]
		void vpe_2901a_2ko_write_single(uint8 channel, uint8 value);
		
		[CCode (cname = "vpe_2901a_2di_read_single")]
		uint8 vpe_2901a_2di_read_single(uint8 channel);
		
		[CCode (cname = "VPE_2901A_SDAFE_1")]
		public const uint8 VPE_2901A_SDAFE_1;
		[CCode (cname = "VPE_2901A_SDAFE_2")]
		public const uint8 VPE_2901A_SDAFE_2;

		[CCode (cname = "vpe_3011b_init")]
		void vpe_3011b_init();
		
		[CCode (cname = "vpe_3011b_4ko_write_single")]
		void vpe_3011b_4ko_write_single(uint8 channel, uint8 value);
		
		[CCode (cname = "vpe_3011b_8di_read")]
		uint8 vpe_3011b_8di_read();
		
		[CCode (cname = "vpe_3011b_8di_read_single")]
		uint8 vpe_3011b_8di_read_single(uint8 channel);
		
		[CCode (cname = "VPE_3011B_SDAFE_1")]
		public const uint8 VPE_3011B_SDAFE_1;
		[CCode (cname = "VPE_3011B_SDAFE_2")]
		public const uint8 VPE_3011B_SDAFE_2;
		[CCode (cname = "VPE_3011B_SDAFE_3")]
		public const uint8 VPE_3011B_SDAFE_3;
		[CCode (cname = "VPE_3011B_SDAFE_4")]
		public const uint8 VPE_3011B_SDAFE_4;
		
		//--------------------------------SDAFE---------------------------------
		[CCode (cname = "enum sdafe_type", cprefix = "", has_type_id = false)]
		public enum SdafeType
		{
			TYPE_1_MA,		// Input 0 to 20 mA, Returns 0 to 20000, Scaler 1000
			TYPE_2_MA,		// Input 0 to 20 mA, Returns 0 to 10000, Scaler 100
			TYPE_3_MA,		// Input 4 to 20 mA, Returns 0 to 10000, Scaler 100 Note: Readings below 4 mA return as 0

			TYPE_4_5VDC,	// Input 0 to 5 VDC, Returns 0 to 5000, Scaler 1000
			TYPE_5_5VDC,	// Input 0 to 5 VDC, Returns 0 to 10000, Scaler 100
			TYPE_6_5VDC,	// Input 1 to 5 VDC, Returns 0 to 10000, Scaler 100 Note: Readngs beluw 1 VDC return as 0

			TYPE_7_10VDC,	// Input 0 to 10 VDC, Returns 0 to 10000, Scaler 1000
			TYPE_8_10VDC,	// Input 0 to 10 VDC, Returns 0 to 10000, Scaler 100
			TYPE_9_10VDC	// Input 2 to 10 VDC, Returns 0 to 10000, Scaler 100 Note: Readings below 2 VDC return as 0	
		}

		[CCode (cname = "enum sdafe_status", cprefix = "SDAFE_", has_type_id = false)]
		public enum SdafeStatus
		{
			OK,
			POLARITY,
			OVER_RANGE,
			COMM_ERROR
		}

		[CCode (cname = "struct sdafe_reading", destroy_function = "", has_type_id = false)]
		public struct SdafeReading
		{
			uint16 value;
			SdafeStatus status;
			uint16 counts;
			SdafeType type;
		}

		[CCode (cname = "sdafe_set_type")]
		void sdafe_set_type(uint8 channel, SdafeType type);
		
		[CCode (cname = "sdafe_read")]
		SdafeReading sdafe_read(uint8 channel);
	}
}
