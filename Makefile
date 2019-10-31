CC		:= gcc
CFLAGS	:= -g


ifeq ($(OS),Windows_NT)
EXECUTABLE	:= hexdumputility.exe
else
EXECUTABLE	:= hexdumputility
endif


$(EXECUTABLE): main.c
	$(CC) $(CFLAGS)  $^ -o $@