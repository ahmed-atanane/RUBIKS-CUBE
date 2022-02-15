TEST = bin/test
RUBIK_TXT = bin/rubikscube_txt
RUBIK_SDL= bin/rubikscube_sdl

OBJ_MAINTXT = obj/txt/maintxt.o
OBJ_MAINSDL = obj/SDL2/mainSDL.o
OBJ_MAINTEST = obj/core/mainTest.o 

OBJ_ACTIONS = obj/core/Actions.o
OBJ_CUBE = obj/core/Cube.o
OBJ_JEU = obj/core/Jeu.o
OBJ_JEUTXT = obj/txt/txtJeu.o
OBJ_WINTXT = obj/txt/winTxt.o
OBJ_SDLJEU=obj/SDL2/SDLJeu.o

H_ACTIONS = src/core/Actions.h
H_CUBE = src/core/Cube.h
H_JEU = src/core/Jeu.h
H_SDLJEU=src/SDL2/SDLJeu.h
H_WINTXT=src/txt/winTxt.h
H_TXTJEU=src/txt/txtJeu.h


CPP_MAINTXT = src/txt/maintxt.cpp
CPP_MAINSDL = src/SDL2/mainSDL.cpp
CPP_MAINTEST = src/core/mainTest.cpp

CPP_ACTIONS = src/core/Actions.cpp
CPP_CUBE = src/core/Cube.cpp
CPP_JEU = src/core/Jeu.cpp
CPP_JEUTXT = src/txt/txtJeu.cpp
CPP_WINTXT = src/txt/winTxt.cpp
CPP_SDLJEU=src/SDL2/SDLJeu.cpp

OBJ_SDL_DIR=obj/SDL2
OBJ_CORE_DIR=obj/core
OBJ_TXT_DIR=obj/txt
BIN_DIR=bin

CC = g++
FLAGS = -ggdb -Wall

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

endif

ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) $(OBJ_DIR)\txt $(OBJ_DIR)\sdl2 $(OBJ_DIR)\core
endif


all: $(TEST) $(RUBIK_TXT) $(RUBIK_SDL)

$(TEST): $(OBJ_MAINTEST) $(OBJ_ACTIONS) $(OBJ_CUBE)
	$(CC) $(FLAGS) $(OBJ_MAINTEST) $(OBJ_ACTIONS) $(OBJ_CUBE) -o $(TEST)

$(RUBIK_TXT): $(OBJ_MAINTXT) $(OBJ_JEUTXT) $(OBJ_WINTXT) $(OBJ_JEU) $(OBJ_ACTIONS) $(OBJ_CUBE)
	$(CC) $(FLAGS) $(OBJ_MAINTXT) $(OBJ_JEUTXT) $(OBJ_WINTXT) $(OBJ_JEU) $(OBJ_ACTIONS) $(OBJ_CUBE) -o $(RUBIK_TXT)

$(RUBIK_SDL): $(OBJ_MAINSDL) $(OBJ_SDLJEU) $(OBJ_JEU) $(OBJ_ACTIONS) $(OBJ_CUBE)
	$(CC) $(FLAGS) $(OBJ_MAINSDL) $(OBJ_SDLJEU) $(OBJ_JEU) $(OBJ_ACTIONS) $(OBJ_CUBE) -o $(RUBIK_SDL) $(INCLUDE_DIR_SDL) $(LIBS_SDL)

$(OBJ_MAINTEST): $(CPP_MAINTEST) $(H_ACTIONS) $(H_CUBE)
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) -c $(CPP_MAINTEST) -o $(OBJ_MAINTEST)

$(OBJ_MAINTXT): $(CPP_MAINTXT) $(H_JEUTXT) $(H_WINTXT) $(H_ACTIONS) 
	$(CC) $(FLAGS) -c $(CPP_MAINTXT) -o $(OBJ_MAINTXT)

$(OBJ_MAINSDL): $(CPP_MAINSDL) $(H_SDLJEU) $(H_JEU) $(H_ACTIONS) $(H_CUBE)
	$(CC) $(FLAGS) -c $(CPP_MAINSDL) -o $(OBJ_MAINSDL) $(INCLUDE_DIR_SDL) $(LIBS_SDL)

$(OBJ_JEUTXT): $(CPP_JEUTXT) $(H_JEUTXT) $(H_WINTXT) $(H_JEU) $(H_ACTIONS)
	$(CC) $(FLAGS) -c $(CPP_JEUTXT) -o $(OBJ_JEUTXT)

$(OBJ_WINTXT): $(CPP_WINTXT) $(H_JEU) $(H_ACTIONS) 
	$(CC) $(FLAGS) -c $(CPP_WINTXT) -o $(OBJ_WINTXT)

$(OBJ_SDLJEU): $(CPP_SDLJEU) $(H_SDLJEU) $(H_JEU) $(H_ACTIONS) $(H_CUBE)
	$(CC) $(FLAGS) -c $(CPP_SDLJEU) -o $(OBJ_SDLJEU) $(INCLUDE_DIR_SDL) $(LIBS_SDL)

$(OBJ_JEU): $(CPP_JEU) $(H_JEU) $(H_ACTIONS) $(H_CUBE)
	$(CC) $(FLAGS) -c $(CPP_JEU) -o $(OBJ_JEU)

$(OBJ_ACTIONS): $(H_ACTIONS) $(CPP_ACTIONS) $(H_CUBE)
	$(CC) $(FLAGS)  $(INCLUDE_DIR_SDL) -c $(CPP_ACTIONS) -o $(OBJ_ACTIONS)

$(OBJ_CUBE): $(H_CUBE) $(CPP_CUBE)
	$(CC) $(FLAGS)  $(INCLUDE_DIR_SDL) -c $(CPP_CUBE) -o $(OBJ_CUBE)

docu: doc/rubikscube.doxy
	cd doc ; doxygen rubikscube.doxy

clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)\txt\*.o $(OBJ_DIR)\sdl2\*.o $(OBJ_DIR)\core\*.o $(BIN_DIR)\$(FINAL_TARGET_TXT).exe $(BIN_DIR)\$(FINAL_TARGET_SDL).exe
else
	rm -rf $(OBJ_SDL_DIR)/*.o $(OBJ_TXT_DIR)/*.o $(OBJ_CORE_DIR)/*.o \
	$(RUBIK_TXT) $(TEST) $(RUBIK_SDL) \
	doc/html
endif
