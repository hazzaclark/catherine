## COPYRIGHT (C) HARRY CLARK 2025
## HITACHI SUPERH INSTRUCTION DECODER

#####################################
## 			   PREFIXES
#####################################

CC				:= gcc
CXX				:= g++
AR 				:= ar
IINC			:= -I inc
IINC_XX			:= -I inc -I c++
CSTD			:= --std=c99
CXX_STD			:= --std=c++17
CFLAGS			:= -fPIC -fno-common
CXXFLAGS		:= -fPIC -fno-common
LDFLAGS			:= -Lbuild -lcath
LDXXFLAGS		:= -Lbuild -lcathcpp
WARNINGS		:= -Wall -Wextra -Wpedantic -Wunused-value -Wunused-parameter -O3

#####################################
## 			  DIRECTORIES
#####################################

SRC_DIR			:= src
C_FILES			:= $(wildcard $(SRC_DIR)/*.c)
H_FILES			:= $(wildcard inc/*.h)
O_FILES			:= $(patsubst $(SRC_DIR)/%.c,build/%.o,$(C_FILES))

SRCX_DIR		:= c++/src
CXX_FILES		:= $(wildcard $(SRCX_DIR)/*.cpp)
HXX_FILES		:= $(wildcard inc/*.hpp)
OXX_FILES		:= $(patsubst $(SRCX_DIR)/%.cpp,build/%.o,$(CXX_FILES))

#####################################
## 			    TARGETS
#####################################

.PHONY: all clean dirs

all: dirs build/libcath.a build/catherine

dirs:
	@mkdir build

build/%.o: $(SRC_DIR)/%.c $(H_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $<

build/%.o: $(SRCX_DIR)/%.cpp $(HXX_FILES)
	$(CXX) -c $(CXX_STD) $(IINC_XX) $(WARNINGS) $(CXXFLAGS) -o $@ $<

build/libcath.a: $(O_FILES)
	$(AR) rcs $@ $^

build/catherine: $(O_FILES)
	$(CC) $(O_FILES) $(LDFLAGS) -o $@

clean:
	rm -rf build