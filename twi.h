void twi_init(void);
void twi_start(uint8_t addr);
void twi_stop(void);
uint8_t twi_read(uint8_t ack);
void twi_write(uint8_t data);
