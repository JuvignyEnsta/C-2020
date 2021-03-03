#include Make_linux.inc
include Make_msys2.inc
#include Make_osx.inc

CXXFLAGS = -std=c++20 `sdl2-config --cflags`
ifdef DEBUG
CXXFLAGS += -g -O0 -Wall -fbounds-check -pedantic -D_GLIBCXX_DEBUG -DDEBUG
else
CXXFLAGS += -O3 -march=native -Wall
endif

LIBS = $(LIB) `sdl2-config --cflags` -lSDL2_ttf -lSDL2_image  `sdl2-config --libs` 
ALL= sdl2_documentation.exe test_sdl.exe

default:	help

all: $(ALL)

clean:
	@rm -fr sdl2/*.o *.exe sdl2/*~ 

OBJS = sdl2/sdl2.o sdl2/geometry.o sdl2/window.o sdl2/font.o sdl2/event.o sdl2/texte.o sdl2/image.o sdl2/formated_text.o

sdl2/sdl2.o:	sdl2/sdl2.hpp sdl2/sdl2.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/sdl2.cpp -o sdl2/sdl2.o

sdl2/geometry.o:	sdl2/geometry.hpp sdl2/window.hpp sdl2/geometry.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/geometry.cpp -o sdl2/geometry.o

sdl2/window.o:	sdl2/window.hpp sdl2/window.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/window.cpp -o sdl2/window.o

sdl2/font.o:	sdl2/window.hpp sdl2/font.hpp sdl2/font.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/font.cpp -o sdl2/font.o

sdl2/event.o : sdl2/window.hpp sdl2/event.hpp sdl2/event.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/event.cpp -o sdl2/event.o

sdl2/texte.o : sdl2/window.hpp sdl2/font.hpp sdl2/texte.hpp sdl2/texte.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/texte.cpp -o sdl2/texte.o

sdl2/formated_texte.o : sdl2/window.hpp sdl2/font.hpp sdl2/formated_text.hpp sdl2/formated_text.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/formated_text.cpp -o sdl2/formated_text.o


sdl2/image.o : sdl2/window.hpp sdl2/image.hpp sdl2/image.cpp
	$(CXX) $(CXXFLAGS) -c sdl2/image.cpp -o sdl2/image.o

sdl2_documentation.exe : $(OBJS) sdl2_documentation.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) sdl2_documentation.cpp -o sdl2_documentation.exe $(LIBS)

test_sdl.exe : $(OBJS) test_sdl.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) test_sdl.cpp -o test_sdl.exe $(LIBS)


help:
	@echo "Available targets : "
	@echo "    all            : compile the executable"
	@echo "    sdl2_documentation.exe     : compile the executable"
	@echo "Add DEBUG=yes to compile in debug"
	@echo "Configuration :"
	@echo "    CXX      :    $(CXX)"
	@echo "    CXXFLAGS :    $(CXXFLAGS)"

show:
	@echo "LIB   : $(LIB)"
	@echo "LIBS  : $(LIBS)"

%.html: %.md
	pandoc -s --toc $< --css=./github-pandoc.css -o $@
