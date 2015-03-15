termo:
	avr-g++ -Os -DF_CPU=1000000 -mmcu=attiny2313 termo.cpp crc8.c onewire.c ds18x20.c -o tmp.elf
	#avr-g++ -DF_CPU=1000000 -mmcu=attiny2313 -o tmp.elf tmp.o
	avr-objcopy -O ihex tmp.elf flash.hex
	#rm tmp.o
	@rm tmp.elf
	@echo "Success"
