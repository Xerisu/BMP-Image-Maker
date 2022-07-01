CC=gcc
CFLAGS=-Wall -Wextra -Werror
OBJDIR=obj
BINDIR=bin
EXENAME=image_maker.exe

all: main 

color: src/utils/color.c src/utils/color.h 
	${CC} ${CFLAGS} -o ${OBJDIR}/color.o -c src/utils/color.c

vector: src/utils/vector.c src/utils/vector.h 
	${CC} ${CFLAGS} -o ${OBJDIR}/vector.o -c src/utils/vector.c

image: src/image/image.c src/image/image.h color vector
	${CC} ${CFLAGS} -o ${OBJDIR}/image.o -c src/image/image.c

bitmap: src/bitmap/bitmap.c src/bitmap/bitmap.h image
	${CC} ${CFLAGS} -o ${OBJDIR}/bitmap.o -c src/bitmap/bitmap.c

main: src/main.c image color vector bitmap
	${CC} ${CFLAGS} -o ${BINDIR}/${EXENAME} src/main.c ${OBJDIR}/*.o 

clean: 
	rm ${OBJDIR}/*.o, ${BINDIR}/${EXENAME}

.PHONY: clean all 