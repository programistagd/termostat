%: %.cpp
	avr-g++ -Os -DF_CPU=1000000 -mmcu=attiny2313 -c $< -o tmp.o
	avr-g++ -DF_CPU=1000000 -mmcu=attiny2313 -o tmp.elf tmp.o
	avr-objcopy -O ihex tmp.elf $@.hex
	rm tmp.o
	rm tmp.elf
