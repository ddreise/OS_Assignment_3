CC		:= gcc
CFLAGS	:= -g


ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif


$(EXECUTABLE): main.c
	$(CC) $(CFLAGS)  $^ -o $@