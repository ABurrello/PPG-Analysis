
#include <stdio.h>
#include <rt/rt_api.h>
#include <stdint.h>
#include "AFE4490.h"
#include "Uart_Debug.h"




#define BUFFER_SIZE 1
#define GPIO 19


//Global variables
volatile uint8_t startread=0;
static void gpio_handler(void *arg)
{
  startread=1;
}


int main()
{


uint32_t AFE44xx_SPO2_Data_buf[6];
Uart_Debug_Init ();

AFE44xx_SPO2_Data_buf[0] = 0;
AFE44xx_SPO2_Data_buf[1] = 0;
AFE44xx_SPO2_Data_buf[2] = 0;
AFE44xx_SPO2_Data_buf[3] = 0;
AFE44xx_SPO2_Data_buf[4] = 0;
AFE44xx_SPO2_Data_buf[5] = 0;
  // First configure the SPI device
  rt_spim_conf_t conf;
  // Get default configuration
  rt_spim_conf_init(&conf);
  // Set maximum baudrate. Can actually be lower than
  // that depending on the best divider found
  conf.max_baudrate = 1000000;
  // SPI interface identifier as the Pulp chip can have
  // several interfaces
  conf.id = 1;
  // Chip select
  conf.cs = 0;

  conf.phase=0;
  conf.polarity=0;


  //GPIO AFE_ADC_DRDY
  if (rt_event_alloc(NULL, 1)) return -1;

  rt_padframe_profile_t *profile_gpio = rt_pad_profile_get("hyper_gpio");

  if (profile_gpio == NULL) {
      printf("pad config error\n");
      return 1;
  }
  rt_padframe_set(profile_gpio);

  // GPIO initialization
  rt_gpio_init(0, GPIO);

  // Configure GPIO as an inpout
  rt_gpio_set_dir(0, 1<<GPIO, RT_GPIO_IS_IN);

  // Trigger notifications on both rising and falling edges
  rt_gpio_set_sensitivity(0, GPIO, RT_GPIO_SENSITIVITY_RISE);

  // Set the event for the GPIO.
  // Note that we use an IRQ event instead of a normal one so that
  // the callback is called directly from the IRQ handler.
  rt_gpio_set_event(0, GPIO, rt_event_irq_get(gpio_handler, (void *)GPIO));



  // Then open the device
  rt_spim_t *spim = rt_spim_open(NULL, &conf, NULL);
  if (spim == NULL) return -1;
  // Set AFE in write mode
  Disable_AFE44x0_SPI_Read(spim);
  //Set AFE registers to deafualt values
  AFE44xx_Default_Reg_Init(spim);
//Set AFE in read mode
  Enable_AFE44x0_SPI_Read(spim);



while(1){

//printf("\n");
//Save a sample every ADC_ready interrupt
if(startread){
  startread=0;
  //printf("funziona\n");
  AFE44xx_SPO2_Data_buf[0] = AFE44x0_Reg_Read(spim,(unsigned char)42);  //read RED Data
  /*AFE44xx_SPO2_Data_buf[1] = AFE44x0_Reg_Read(spim,(unsigned char)43);  //read Ambient data
  AFE44xx_SPO2_Data_buf[2] = AFE44x0_Reg_Read(spim,(unsigned char)44);  //read IR Data
  AFE44xx_SPO2_Data_buf[3] = AFE44x0_Reg_Read(spim,(unsigned char)45);  //read Ambient Data
  AFE44xx_SPO2_Data_buf[4] = AFE44x0_Reg_Read(spim,(unsigned char)46);  //read RED - Ambient Data
  AFE44xx_SPO2_Data_buf[5] = AFE44x0_Reg_Read(spim,(unsigned char)47);  //read */ //IR - Ambient Data
  //printf("Valore ir %i\n",AFE44xx_SPO2_Data_buf[0]);

  char prova[50];
	int n = sprintf(prova, "%d \n \r",AFE44xx_SPO2_Data_buf[0]);
	DEBUG_STR(prova);


}
}
}
