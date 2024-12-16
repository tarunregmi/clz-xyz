CC = g++
FLAGS = -lGL -lGLU -lglut -O2
SRC = ./
OUT = out
OUT_STATIC = out_static

all: build clean

build:
	@echo building...
	@$(CC) -o $(OUT) $(f) $(FLAGS)
	@strip $(OUT)
	@staticx $(OUT) $(OUT_STATIC)
	@strip $(OUT_STATIC)

clean:
	@echo cleanning...
	@rm -f $(OUT)

# g++ -o out main.cpp -lGL -lGLU -lglut -O2
# strip out
# staticx out out_static
# strip out_static
