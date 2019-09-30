#include "AFE4490.h"
#include <stdio.h>
#include <rt/rt_api.h>
#include <stdint.h>


void Enable_AFE44x0_SPI_Read (rt_spim_t * spim)
{

   unsigned char *tx_buffer = rt_alloc(RT_ALLOC_PERIPH, 1);
  tx_buffer[0]=0;
  rt_spim_send(
    spim, tx_buffer,8, RT_SPIM_CS_KEEP, NULL
  );
  tx_buffer[0]=0;
  rt_spim_send(
    spim, tx_buffer,8, RT_SPIM_CS_KEEP, NULL
  );
  tx_buffer[0]=0;
  rt_spim_send(
    spim, tx_buffer,8, RT_SPIM_CS_KEEP, NULL
  );
  tx_buffer[0]=1;
  rt_spim_send(
    spim, tx_buffer,8, RT_SPIM_CS_AUTO, NULL
  );


                     // CS High for end of transmission

}


void Disable_AFE44x0_SPI_Read (	rt_spim_t * spim)
{

  unsigned char *tx_buffer = rt_alloc(RT_ALLOC_PERIPH, 1);
 tx_buffer[0]=0;
 rt_spim_send(
   spim, tx_buffer,8, RT_SPIM_CS_KEEP , NULL
 );
 tx_buffer[0]=0;
 rt_spim_send(
   spim, tx_buffer,8, RT_SPIM_CS_KEEP, NULL
 );
 tx_buffer[0]=0;
 rt_spim_send(
   spim, tx_buffer,8, RT_SPIM_CS_KEEP, NULL
 );
 tx_buffer[0]=0;
 rt_spim_send(
   spim, tx_buffer,8, RT_SPIM_CS_AUTO, NULL
 );                      // CS High for end of transmission
}

void AFE44x0_Reg_Write (rt_spim_t * spim ,unsigned char  reg_address,
  uint32_t data)
{

  unsigned char* reg_address_send = rt_alloc(RT_ALLOC_PERIPH, 1);
  reg_address_send[0]=reg_address;

  rt_spim_send(
    spim, reg_address_send, 8, RT_SPIM_CS_KEEP, NULL
  );

  unsigned char* send_data=rt_alloc(RT_ALLOC_PERIPH,1);
  send_data[0]=(unsigned char) ((data & 0x00FF0000) >>16);
  rt_spim_send(
    spim, send_data, 8, RT_SPIM_CS_KEEP,NULL
  );
  send_data[0]=(unsigned char) ((data & 0x0000FF00) >>8);

  rt_spim_send(
    spim, send_data, 8, RT_SPIM_CS_KEEP,NULL
  );
  send_data[0]=(unsigned char) (((data & 0x00000FF)));

  rt_spim_send(
    spim, send_data, 8, RT_SPIM_CS_AUTO,NULL
  );


}


uint32_t AFE44x0_Reg_Read(rt_spim_t * spim,unsigned char Reg_address)
{
   unsigned char SPI_Rx_buf[3];
   unsigned long retVal;
   retVal=0;
   unsigned char* reg_address_send = rt_alloc(RT_ALLOC_PERIPH, 1);
   reg_address_send[0]=Reg_address;

   rt_spim_send(
     spim, reg_address_send, 8, RT_SPIM_CS_KEEP, NULL
   );
  unsigned char* rx_buff=rt_alloc(RT_ALLOC_PERIPH,1);

  rt_spim_receive(
    spim, rx_buff, 8, RT_SPIM_CS_KEEP, NULL
  );
  SPI_Rx_buf[0]=rx_buff[0];
  rt_spim_receive(
    spim, rx_buff, 8, RT_SPIM_CS_KEEP, NULL
  );
  SPI_Rx_buf[1]=rx_buff[0];
  rt_spim_receive(
    spim, rx_buff, 8, RT_SPIM_CS_AUTO, NULL
  );
  SPI_Rx_buf[2]=rx_buff[0];
  retVal=SPI_Rx_buf[0];
  retVal = (retVal << 8) | SPI_Rx_buf[1];
  retVal = (retVal << 8) | SPI_Rx_buf[2];
  return 	retVal;
}


uint32_t AFE44xx_Current_Register_Settings[36] = {
  CONTROL0_VAL,           //Reg0:CONTROL0: CONTROL REGISTER 0
  LED2STC_VAL,            //Reg1:REDSTARTCOUNT: SAMPLE RED START COUNT
  LED2ENDC_VAL,           //Reg2:REDENDCOUNT: SAMPLE RED END COUNT
  LED2LEDSTC_VAL,         //Reg3:REDLEDSTARTCOUNT: RED LED START COUNT
  LED2LEDENDC_VAL,        //Reg4:REDLEDENDCOUNT: RED LED END COUNT
  ALED2STC_VAL,           //Reg5:AMBREDSTARTCOUNT: SAMPLE AMBIENT RED START COUNT
  ALED2ENDC_VAL,          //Reg6:AMBREDENDCOUNT: SAMPLE AMBIENT RED END COUNT
  LED1STC_VAL,            //Reg7:IRSTARTCOUNT: SAMPLE IR START COUNT
  LED1ENDC_VAL,           //Reg8:IRENDCOUNT: SAMPLE IR END COUNT
  LED1LEDSTC_VAL,         //Reg9:IRLEDSTARTCOUNT: IR LED START COUNT
  LED1LEDENDC_VAL,        //Reg10:IRLEDENDCOUNT: IR LED END COUNT
  ALED1STC_VAL,           //Reg11:AMBIRSTARTCOUNT: SAMPLE AMBIENT IR START COUNT
  ALED1ENDC_VAL,          //Reg12:AMBIRENDCOUNT: SAMPLE AMBIENT IR END COUNT
  LED2CONVST_VAL,         //Reg13:REDCONVSTART: REDCONVST
  LED2CONVEND_VAL,        //Reg14:REDCONVEND: RED CONVERT END COUNT
  ALED2CONVST_VAL,        //Reg15:AMBREDCONVSTART: RED AMBIENT CONVERT START COUNT
  ALED2CONVEND_VAL,       //Reg16:AMBREDCONVEND: RED AMBIENT CONVERT END COUNT
  LED1CONVST_VAL,         //Reg17:IRCONVSTART: IR CONVERT START COUNT
  LED1CONVEND_VAL,        //Reg18:IRCONVEND: IR CONVERT END COUNT
  ALED1CONVST_VAL,        //Reg19:AMBIRCONVSTART: IR AMBIENT CONVERT START COUNT
  ALED1CONVEND_VAL,       //Reg20:AMBIRCONVEND: IR AMBIENT CONVERT END COUNT
  ADCRSTSTCT0_VAL,        //Reg21:ADCRESETSTCOUNT0: ADC RESET 0 START COUNT
  ADCRSTENDCT0_VAL,       //Reg22:ADCRESETENDCOUNT0: ADC RESET 0 END COUNT
  ADCRSTSTCT1_VAL,        //Reg23:ADCRESETSTCOUNT1: ADC RESET 1 START COUNT
  ADCRSTENDCT1_VAL,       //Reg24:ADCRESETENDCOUNT1: ADC RESET 1 END COUNT
  ADCRSTSTCT2_VAL,        //Reg25:ADCRESETENDCOUNT2: ADC RESET 2 START COUNT
  ADCRSTENDCT2_VAL,       //Reg26:ADCRESETENDCOUNT2: ADC RESET 2 END COUNT
  ADCRSTSTCT3_VAL,        //Reg27:ADCRESETENDCOUNT3: ADC RESET 3 START COUNT
  ADCRSTENDCT3_VAL,       //Reg28:ADCRESETENDCOUNT3: ADC RESET 3 END COUNT
  PRP,                    //Reg29:PRPCOUNT: PULSE REPETITION PERIOD COUNT
  CONTROL1_VAL,           //Reg30:CONTROL1: CONTROL REGISTER 1 //timer enabled, averages=3, RED and IR LED pulse ON PD_ALM AND LED_ALM pins
  0x00000,                //Reg31:?: ??
  (ENSEPGAIN + STAGE2EN_LED1 + STG2GAIN_LED1_0DB + CF_LED1_5P + RF_LED1_1M),                      //Reg32:TIAGAIN: TRANS IMPEDANCE AMPLIFIER GAIN SETTING REGISTER
  (AMBDAC_0uA + FLTRCNRSEL_500HZ + STAGE2EN_LED2 + STG2GAIN_LED2_0DB + CF_LED2_5P + RF_LED2_1M),  //Reg33:TIA_AMB_GAIN: TRANS IMPEDANCE AAMPLIFIER AND AMBIENT CANELLATION STAGE GAIN
  (LEDCNTRL_VAL),                                                                                 //Reg34:LEDCNTRL: LED CONTROL REGISTER
  (TX_REF_1 + RST_CLK_ON_PD_ALM_PIN_DISABLE + ADC_BYP_DISABLE + TXBRGMOD_H_BRIDGE + DIGOUT_TRISTATE_DISABLE + XTAL_ENABLE + EN_FAST_DIAG + PDN_TX_OFF + PDN_RX_OFF + PDN_AFE_OFF)                 //Reg35:CONTROL2: CONTROL REGISTER 2 //bit 9
};

void AFE44xx_Default_Reg_Init(rt_spim_t * spim)
{

  Disable_AFE44x0_SPI_Read(spim);


  AFE44x0_Reg_Write(spim,(unsigned char)PRPCOUNT, (uint32_t)PRP);

  AFE44x0_Reg_Write(spim,(unsigned char)LED2STC, (uint32_t)LED2STC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED2ENDC, (uint32_t)LED2ENDC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED2LEDSTC, (uint32_t)LED2LEDSTC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED2LEDENDC, (uint32_t)LED2LEDENDC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED2STC, (uint32_t)ALED2STC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED2ENDC, (uint32_t)ALED2ENDC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED1STC, (uint32_t)LED1STC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED1ENDC, (uint32_t)LED1ENDC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED1LEDSTC, (uint32_t)LED1LEDSTC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED1LEDENDC, (uint32_t)LED1LEDENDC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED1STC, (uint32_t)ALED1STC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED1ENDC, (uint32_t)ALED1ENDC_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED2CONVST, (uint32_t)LED2CONVST_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED2CONVEND, (uint32_t)LED2CONVEND_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED2CONVST, (uint32_t)ALED2CONVST_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED2CONVEND, (uint32_t)ALED2CONVEND_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED1CONVST, (uint32_t)LED1CONVST_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)LED1CONVEND, (uint32_t)LED1CONVEND_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED1CONVST, (uint32_t)ALED1CONVST_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ALED1CONVEND, (uint32_t)ALED1CONVEND_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTSTCT0, (uint32_t)ADCRSTSTCT0_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTENDCT0, (uint32_t)ADCRSTENDCT0_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTSTCT1, (uint32_t)ADCRSTSTCT1_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTENDCT1, (uint32_t)ADCRSTENDCT1_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTSTCT2, (uint32_t)ADCRSTSTCT2_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTENDCT2, (uint32_t)ADCRSTENDCT2_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTSTCT3, (uint32_t)ADCRSTSTCT3_VAL);

  AFE44x0_Reg_Write(spim,(unsigned char)ADCRSTENDCT3, (uint32_t)ADCRSTENDCT3_VAL);


  AFE44x0_Reg_Write(spim,(unsigned char)CONTROL0, AFE44xx_Current_Register_Settings[0]);
              //0x00
  AFE44x0_Reg_Write(spim,(unsigned char)CONTROL2, AFE44xx_Current_Register_Settings[35]);
           //0x23
  AFE44x0_Reg_Write(spim,(unsigned char)TIAGAIN, AFE44xx_Current_Register_Settings[32]);
              //0x20
  AFE44x0_Reg_Write(spim,(unsigned char)TIA_AMB_GAIN, AFE44xx_Current_Register_Settings[33]);
        //0x21
  AFE44x0_Reg_Write(spim,(unsigned char)LEDCNTRL, AFE44xx_Current_Register_Settings[34]);
            //0x22
  AFE44x0_Reg_Write(spim,(unsigned char)CONTROL1, AFE44xx_Current_Register_Settings[30]);
             //0x1E

  Enable_AFE44x0_SPI_Read(spim);

}
