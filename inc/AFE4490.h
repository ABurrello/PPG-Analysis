
#ifndef _AFE4490_H_
#define _AFE4490_H_

#include <stdio.h>
#include <rt/rt_api.h>
#include <stdint.h>

/*----------------------------------------------------------------------------+
| Constant Definition                                                         |
+----------------------------------------------------------------------------*/

#define PRF             100
#define DUTYCYCLE       20
#define AFECLK          4000000

// CONTROL0 - Write Only register
#define CONTROL0        0x00
#define    CONTROL0_VAL (0x00000000)
#define    SPI_READ     (0x00000001)        //SPI read
#define    TIM_CNT_RST  (0x00000002)        //Timer counter reset
#define    DIAG_EN      (0x00000004)        //Diagnostic enable
#define    SW_RST        0x00000008        //Software reset

// CONTROL1 - Read/Write register
#define CONTROL1        0x1E
#define    CONTROL1_VAL                         (TIMEREN + NUMAV)
#define    SAMPLE_LED2_SAMPLE_LED1              (0x00000000)        //Clocks on ALM pins
#define    LED2_PSE_LED1_PSE                (0x00000200)        //Clocks on ALM pins
#define    SAMPLE_LED2_SAMPLE_LED1_PSE        (0x00000400)        //Clocks on ALM pins
#define    LED2_CONVERT_LED1_CONVERT            (0x00000600)        //Clocks on ALM pins
#define    LED2_AMBIENT_LED1_AMBIENT            (0x00000800)        //Clocks on ALM pins
#define    NO_OUTPUT_NO_OUTPUT                  (0x00000A00)        //Clocks on ALM pins
#define    TIMEREN                              (0x00000100)//Timer enable
//#define NUMAV                                 (0x000009)        //Number of averages-1 (8 bits [LSB])
#define    NUMAV                                (0x00000007)        //Number of averages-1 (8 bits [LSB])

#define TIAGAIN         0x20
#define    TIAGAIN_VAL                 (0x00000000)
#define    RF_LED1_500K                (0x00000000)        //Program RF for LED1
#define    RF_LED1_250K                (0x00000001)        //Program RF for LED1
#define    RF_LED1_100K                (0x00000002)        //Program RF for LED1
#define    RF_LED1_50K                 (0x00000003)        //Program RF for LED1
#define    RF_LED1_25K                 (0x00000004)        //Program RF for LED1
#define    RF_LED1_10K                 (0x00000005)        //Program RF for LED1
#define    RF_LED1_1M                  (0x00000006)        //Program RF for LED1
#define    RF_LED1_NONE                (0x00000007)        //Program RF for LED1

#define    CF_LED1_5P                  (0x000000)        //Program CF for LED1
#define    CF_LED1_5P_5P               (0x000008)        //Program CF for LED1
#define    CF_LED1_15P_5P              (0x000010)        //Program CF for LED1
#define    CF_LED1_20P_5P              (0x000018)        //Program CF for LED1
#define    CF_LED1_25P_5P              (0x000020)        //Program CF for LED1
#define    CF_LED1_30P_5P              (0x000028)        //Program CF for LED1
#define    CF_LED1_40P_5P              (0x000030)        //Program CF for LED1
#define    CF_LED1_45P_5P              (0x000038)        //Program CF for LED1
#define    CF_LED1_50P_5P              (0x000040)        //Program CF for LED1
#define    CF_LED1_55P_5P              (0x000048)        //Program CF for LED1
#define    CF_LED1_65P_5P              (0x000050)        //Program CF for LED1
#define    CF_LED1_70P_5P              (0x000058)        //Program CF for LED1
#define    CF_LED1_75P_5P              (0x000060)        //Program CF for LED1
#define    CF_LED1_80P_5P              (0x000068)        //Program CF for LED1
#define    CF_LED1_90P_5P              (0x000070)        //Program CF for LED1
#define    CF_LED1_95P_5P              (0x000078)        //Program CF for LED1
#define    CF_LED1_150P_5P             (0x000080)        //Program CF for LED1
#define    CF_LED1_155P_5P             (0x000088)        //Program CF for LED1
#define    CF_LED1_165P_5P             (0x000090)        //Program CF for LED1
#define    CF_LED1_170P_5P             (0x000098)        //Program CF for LED1
#define    CF_LED1_175P_5P             (0x0000A0)        //Program CF for LED1
#define    CF_LED1_180P_5P             (0x0000A8)        //Program CF for LED1
#define    CF_LED1_190P_5P             (0x0000B0)        //Program CF for LED1
#define    CF_LED1_195P_5P             (0x0000B8)        //Program CF for LED1
#define    CF_LED1_200P_5P             (0x0000C0)        //Program CF for LED1
#define    CF_LED1_205P_5P             (0x0000C8)        //Program CF for LED1
#define    CF_LED1_215P_5P             (0x0000D0)        //Program CF for LED1
#define    CF_LED1_220P_5P             (0x0000D8)        //Program CF for LED1
#define    CF_LED1_225P_5P             (0x0000E0)        //Program CF for LED1
#define    CF_LED1_230P_5P             (0x0000E8)        //Program CF for LED1
#define    CF_LED1_240P_5P             (0x0000F0)        //Program CF for LED1
#define    CF_LED1_245P_5P             (0x0000F8)        //Program CF for LED1

#define    STG2GAIN_LED1_0DB           0x000000        //Stage 2 gain setting for LED1
#define    STG2GAIN_LED1_3DB           0x000100        //Stage 2 gain setting for LED1
#define    STG2GAIN_LED1_6DB           0x000200        //Stage 2 gain setting for LED1
#define    STG2GAIN_LED1_9DB           0x000300        //Stage 2 gain setting for LED1
#define    STG2GAIN_LED1_12DB          0x000400        //Stage 2 gain setting for LED1
#define    STG2GAIN_LED1               0x000700        //Stage 2 gain setting for LED1

#define    STAGE2EN_LED1               0x004000        //Stage 2 enable for LED1
#define    ENSEPGAIN                   0x008000


#define TIA_AMB_GAIN    0x21
#define    TIA_AMB_GAIN_VAL            0x000000
#define    RF_LED2_500K                0x000000        //Program RF for LED2
#define    RF_LED2_250K                0x000001        //Program RF for LED2
#define    RF_LED2_100K                0x000002        //Program RF for LED2
#define    RF_LED2_50K                 0x000003        //Program RF for LED2
#define    RF_LED2_25K                 0x000004        //Program RF for LED2
#define    RF_LED2_10K                 0x000005        //Program RF for LED2
#define    RF_LED2_1M                  0x000006        //Program RF for LED2
#define    RF_LED2_NONE                0x000007        //Program RF for LED2

#define    CF_LED2_5P                  0x000000        //Program CF for LED2
#define    CF_LED2_5P_5P               0x000008        //Program CF for LED2
#define    CF_LED2_15P_5P              0x000010        //Program CF for LED2
#define    CF_LED2_20P_5P              0x000018        //Program CF for LED2
#define    CF_LED2_25P_5P              0x000020        //Program CF for LED2
#define    CF_LED2_30P_5P              0x000028        //Program CF for LED2
#define    CF_LED2_40P_5P              0x000030        //Program CF for LED2
#define    CF_LED2_45P_5P              0x000038        //Program CF for LED2
#define    CF_LED2_50P_5P              0x000040        //Program CF for LED2
#define    CF_LED2_55P_5P              0x000048        //Program CF for LED2
#define    CF_LED2_65P_5P              0x000050        //Program CF for LED2
#define    CF_LED2_70P_5P              0x000058        //Program CF for LED2
#define    CF_LED2_75P_5P              0x000060        //Program CF for LED2
#define    CF_LED2_80P_5P              0x000068        //Program CF for LED2
#define    CF_LED2_90P_5P              0x000070        //Program CF for LED2
#define    CF_LED2_95P_5P              0x000078        //Program CF for LED2
#define    CF_LED2_150P_5P             0x000080        //Program CF for LED2
#define    CF_LED2_155P_5P             0x000088        //Program CF for LED2
#define    CF_LED2_165P_5P             0x000090        //Program CF for LED2
#define    CF_LED2_170P_5P             0x000098        //Program CF for LED2
#define    CF_LED2_175P_5P             0x0000A0        //Program CF for LED2
#define    CF_LED2_180P_5P             0x0000A8        //Program CF for LED2
#define    CF_LED2_190P_5P             0x0000B0        //Program CF for LED2
#define    CF_LED2_195P_5P             0x0000B8        //Program CF for LED2
#define    CF_LED2_200P_5P             0x0000C0        //Program CF for LED2
#define    CF_LED2_205P_5P             0x0000C8        //Program CF for LED2
#define    CF_LED2_215P_5P             0x0000D0        //Program CF for LED2
#define    CF_LED2_220P_5P             0x0000D8        //Program CF for LED2
#define    CF_LED2_225P_5P             0x0000E0        //Program CF for LED2
#define    CF_LED2_230P_5P             0x0000E8        //Program CF for LED2
#define    CF_LED2_240P_5P             0x0000F0        //Program CF for LED2
#define    CF_LED2_245P_5P             0x0000F8        //Program CF for LED2

#define    STG2GAIN_LED2_0DB           0x000000        //Stage 2 gain setting for LED2
#define    STG2GAIN_LED2_3DB           0x000100        //Stage 2 gain setting for LED2
#define    STG2GAIN_LED2_6DB           0x000200        //Stage 2 gain setting for LED2
#define    STG2GAIN_LED2_9DB           0x000300        //Stage 2 gain setting for LED2
#define    STG2GAIN_LED2_12DB          0x000400        //Stage 2 gain setting for LED2
#define    STG2GAIN_LED2               0x000700        //Stage 2 gain setting for LED2

#define    STAGE2EN_LED2               0x004000        //Stage 2 enable for LED2

#define    FLTRCNRSEL_500HZ            0x000000        //Filter corner selection
#define    FLTRCNRSEL_1000HZ           0x008000        //Filter corner selection

#define    AMBDAC_0uA                  0x000000        //Ambient DAC value
#define    AMBDAC_1uA                  0x010000        //Ambient DAC value
#define    AMBDAC_2uA                  0x020000        //Ambient DAC value
#define    AMBDAC_3uA                  0x030000        //Ambient DAC value
#define    AMBDAC_4uA                  0x040000        //Ambient DAC value
#define    AMBDAC_5uA                  0x050000        //Ambient DAC value
#define    AMBDAC_6uA                  0x060000        //Ambient DAC value
#define    AMBDAC_7uA                  0x070000        //Ambient DAC value
#define    AMBDAC_8uA                  0x080000        //Ambient DAC value
#define    AMBDAC_9uA                  0x090000        //Ambient DAC value
#define    AMBDAC_10uA                 0x0A0000        //Ambient DAC value

#define LEDCNTRL        0x22
#define    LEDCNTRL_VAL                (0x011414)
#define    LED2_CURRENT                (0x0000FF)        //Program LED current for LED2 signal
#define    LED1_CURRENT                (0x00FF00)        //Program LED current for LED1 signal
#define    LED_RANGE_0                 (0x000000)        //Fl-Scale LED current range   // 150mA / 100mA / 200mA / 150mA
#define    LED_RANGE_1                 (0x010000)        //Fl-Scale LED current range   // 75mA  / 50mA  / 100mA / 75mA
#define    LED_RANGE_2                 (0x020000)        //Fl-Scale LED current range   // 150mA / 100mA / 200mA / 150mA
#define    LED_RANGE_3                 (0x030000)        //Fl-Scale LED current range   // OFF   / OFF   / OFF   / OFF



#define CONTROL2        0x23
#define CONTROL2_VAL                    (0x000000)
#define PDN_AFE_OFF                     (0x000000)        //AFE power-down (Powered on)
#define PDN_AFE_ON                      (0x000001)        //AFE power-down (Powered off)

#define PDN_RX_OFF                      (0x000000)        //Rx power-down (Powered on)
#define PDN_RX_ON                       (0x000002)        //Rx power-down (Powered off)

#define PDN_TX_OFF                      (0x000000)        //Tx power-down (Powered on)
#define PDN_TX_ON                       (0x000004)        //Tx power-down (Powered off)

#define EN_FAST_DIAG                    (0x000000)        //Fast diagnostics mode enable
#define EN_SLOW_DIAG                    (0x000100)        //Slow diagnostics mode enable

#define XTAL_ENABLE                     (0x000000)        //The crystal mode is enabled
#define XTAL_DISABLE                    (0x000200)        //The crystal mode is disabled

#define DIGOUT_TRISTATE_DISABLE         (0x000000)        //Digital tristate disabled
#define DIGOUT_TRISTATE_ENABLE          (0x000400)        //Digital tristate enabled

#define TXBRGMOD_H_BRIDGE               (0x000000)        //Tx bridge mode
#define TXBRGMOD_PUSH_PL              (0x000800)        //Tx bridge mode

#define ADC_BYP_DISABLE                 (0x000000)        //ADC bypass mode enable
#define ADC_BYP_ENABLE                  (0x008000)        //ADC bypass mode enable

#define RST_CLK_ON_PD_ALM_PIN_DISABLE   (0x000000)        //RST CLK on PD_ALM pin disable
#define RST_CLK_ON_PD_ALM_PIN_ENABLE    (0x010000)        //RST CLK on PD_ALM pin enable

#define TX_REF_0                        (0x000000)        //Tx reference voltage - 0.75V
#define TX_REF_1                        (0x020000)        //Tx reference voltage - 0.5V
#define TX_REF_2                        (0x040000)        //Tx reference voltage - 1.0V
#define TX_REF_3                        (0x060000)        //Tx reference voltage - 0.75V


#define ALARM           0x29
#define    ALARM_VAL                    (0x000000)
#define    ALMPINCLKEN                  (0x000080)        //Alarm pin clock enable (Enables CLKALMPIN)

// Read only registers
#define LED2VAL         0x2A
#define ALED2VAL        0x2B
#define LED1VAL         0x2C
#define ALED1VAL        0x2D
#define LED2_ALED2VAL   0x2E
#define LED1_ALED1VAL   0x2F
#define DIAG            0x30
// End of Read only registers

#define PRPCOUNT        0x1D
#define PRP             ((AFECLK/PRF)-1)                // for 100HZ - 39999

#define DELTA           (((PRP+1)*DUTYCYCLE)/100)       // for 100HZ - 8000
#define CONV_DELTA      ((PRP+1)/4)                     // for 100HZ - 10000
#define ADCRESET_DELAY  5

#define LED2STC         0x01
#define LED2STC_VAL     ((((PRP+1)*3)/4)+80)            // for 100HZ - 30080

#define LED2ENDC        0x02
#define LED2ENDC_VAL    (LED2STC_VAL-80+DELTA-2)        // for 100HZ - 37998

#define LED2LEDSTC      0x03
#define LED2LEDSTC_VAL  (LED2STC_VAL-80)                // for 100HZ - 30000

#define LED2LEDENDC     0x04
#define LED2LEDENDC_VAL (LED2ENDC_VAL+1)                // for 100HZ - 37999

#define ALED2STC        0x05
#define ALED2STC_VAL    80                              // for 100HZ - 80

#define ALED2ENDC       0x06
#define ALED2ENDC_VAL   (DELTA-2)                       // for 100HZ - 7998

#define LED1STC         0x07
#define LED1STC_VAL     (((PRP+1)/4)+80)                // for 100HZ - 10080

#define LED1ENDC        0x08
#define LED1ENDC_VAL    (LED1STC_VAL-80+DELTA-2)        // for 100HZ - 17998

#define LED1LEDSTC      0x09
#define LED1LEDSTC_VAL  (LED1STC_VAL-80)                // for 100HZ - 10000

#define LED1LEDENDC     0x0A
#define LED1LEDENDC_VAL (LED1ENDC_VAL+1)                // for 100HZ - 17999

#define ALED1STC        0x0B
#define ALED1STC_VAL    (((PRP+1)/2)+80)                // for 100HZ - 20080

#define ALED1ENDC       0x0C
#define ALED1ENDC_VAL   (ALED1STC_VAL-80+DELTA-2)       // for 100HZ - 27998

#define LED2CONVST      0x0D
#define LED2CONVST_VAL  (ADCRESET_DELAY+2)              // for 100HZ - 6

#define LED2CONVEND     0x0E
#define LED2CONVEND_VAL (LED2CONVST_VAL-(ADCRESET_DELAY+1)+CONV_DELTA-1)        // for 100HZ - 9999

#define ALED2CONVST     0x0F
#define ALED2CONVST_VAL (CONV_DELTA+7)                  // for 100HZ - 10006

#define ALED2CONVEND    0x10
#define ALED2CONVEND_VAL (ALED2CONVST_VAL-(ADCRESET_DELAY+1)+CONV_DELTA-1)      // for 100HZ - 19999

#define LED1CONVST      0x11
#define LED1CONVST_VAL  ((CONV_DELTA*2)+(ADCRESET_DELAY+2))     // for 100HZ - 20006

#define LED1CONVEND     0x12
#define LED1CONVEND_VAL (LED1CONVST_VAL-(ADCRESET_DELAY+1)+CONV_DELTA-1)        // for 100HZ - 29999

#define ALED1CONVST     0x13
#define ALED1CONVST_VAL ((CONV_DELTA*3)+(ADCRESET_DELAY+2))     // for 100HZ - 30006

#define ALED1CONVEND    0x14
#define ALED1CONVEND_VAL (ALED1CONVST_VAL-(ADCRESET_DELAY+1)+CONV_DELTA-1)      // for 100HZ - 39999

#define ADCRSTSTCT0     0x15
#define ADCRSTSTCT0_VAL 0       // for 100HZ - 0

#define ADCRSTENDCT0    0x16
#define ADCRSTENDCT0_VAL (ADCRSTSTCT0_VAL+ADCRESET_DELAY)       // for 100HZ - 5

#define ADCRSTSTCT1     0x17
#define ADCRSTSTCT1_VAL CONV_DELTA      // for 100HZ - 10000

#define ADCRSTENDCT1    0x18
#define ADCRSTENDCT1_VAL (ADCRSTSTCT1_VAL+ADCRESET_DELAY)       // for 100HZ - 10005

#define ADCRSTSTCT2     0x19
#define ADCRSTSTCT2_VAL (CONV_DELTA*2)  // for 100HZ - 20000

#define ADCRSTENDCT2    0x1A
#define ADCRSTENDCT2_VAL (ADCRSTSTCT2_VAL+ADCRESET_DELAY)       // for 100HZ - 20005

#define ADCRSTSTCT3     0x1B
#define ADCRSTSTCT3_VAL (CONV_DELTA*3)  // for 100HZ - 30000

#define ADCRSTENDCT3    0x1C
#define ADCRSTENDCT3_VAL (ADCRSTSTCT3_VAL+ADCRESET_DELAY)       // for 100HZ - 30005

/****************************************************************/
/* Global functions*/
/****************************************************************/

void AFE44xx_Defat_Reg_Init(rt_spim_t * spim);

void AFE44x0_Reg_Write (rt_spim_t * spim ,unsigned char  reg_address,
  uint32_t data);
uint32_t AFE44x0_Reg_Read(rt_spim_t * spim,unsigned char Reg_address);
void Enable_AFE44x0_SPI_Read (rt_spim_t * spim);
void Disable_AFE44x0_SPI_Read (	rt_spim_t * spim);


#endif
