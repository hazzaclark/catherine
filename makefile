## COPYRIGHT (C) HARRY CLARK 2025
## HITACHI SUPERH INSTRUCTION DECODER

#####################################
## 			   PREFIXES
#####################################

CC				:= gcc
CXX				:= g++
AR 				:= ar
IINC			:= -I inc
IINC_XX			:= -I inc -I cplusplus
CSTD			:= --std=c99
CXX_STD			:= --std=c++17
CFLAGS			:= -fPIC -fno-common
CXXFLAGS		:= -fPIC -fno-common
LDFLAGS			:= -Lbuild -lcath
LDXXFLAGS		:= -Lbuild -lcathcxx
WARNINGS		:= -Wall -Wextra -Wpedantic -Wunused-value -Wunused-parameter -O3

#####################################
## 			  DIRECTORIES
#####################################

SRC_DIR			:= src
TABLES_DIR		:= inc/tables
C_FILES			:= $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(TABLES_DIR)/*.c)
H_FILES			:= $(wildcard inc/*.h) \
				   $(wildcard inc/enums/*.h) \
				   $(wildcard inc/instructions/*.h) \
				   $(wildcard inc/tables/*.h)
INC_FILES		:= $(wildcard inc/tables/*.inc)
O_FILES			:= $(patsubst $(SRC_DIR)/%.c,build/%.o,$(filter $(SRC_DIR)/%.c,$(C_FILES))) \
				   $(patsubst $(SRC_DIR)/%,build/%,$(patsubst %.c,%.o,$(filter $(SRC_DIR)/%/*.c,$(C_FILES)))) \
				   $(patsubst $(TABLES_DIR)/%.c,build/tables_%.o,$(filter $(TABLES_DIR)/%.c,$(C_FILES)))

SRCX_DIR		:= cplusplus/src
CXX_FILES		:= $(wildcard $(SRCX_DIR)/*.cpp)
HXX_FILES		:= $(wildcard cplusplus/*.hpp) $(wildcard inc/*.hpp)
OXX_FILES		:= $(patsubst $(SRCX_DIR)/%.cpp,build/%.o,$(CXX_FILES))

#####################################
## 			    TARGETS
#####################################

.PHONY: all clean dirs cxx

all: dirs build/libcath.a build/catherine

cxx: dirs build/libcathcxx.a

dirs:
	@mkdir -p build/instructions

build/%.o: $(SRC_DIR)/%.c $(H_FILES) $(INC_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $(SRC_DIR)/$*.c

build/instructions/%.o: $(SRC_DIR)/instructions/%.c $(H_FILES) $(INC_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $(SRC_DIR)/instructions/$*.c

build/tables_%.o: $(TABLES_DIR)/%.c $(H_FILES) $(INC_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $(TABLES_DIR)/$*.c

build/%.o: $(SRCX_DIR)/%.cpp $(HXX_FILES)
	$(CXX) -c $(CXX_STD) $(IINC_XX) $(WARNINGS) $(CXXFLAGS) -o $@ $(SRCX_DIR)/$*.cpp

build/libcath.a: $(O_FILES)
	$(AR) rcs $@ $^

build/libcathcxx.a: $(OXX_FILES)
	$(AR) rcs $@ $^

build/catherine: $(O_FILES)
	$(CC) $(O_FILES) $(LDFLAGS) -o $@

clean:
	rm -rf build
