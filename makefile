## COPYRIGHT (C) HARRY CLARK 2025
## HITACHI SUPERH INSTRUCTION DECODER

#####################################
##             PREFIXES
#####################################

CC              := gcc
CXX             := g++
AR              := ar
IINC            := -I inc
IINC_XX         := -I cplusplus/inc -I inc
CSTD            := --std=c99
CXX_STD         := --std=c++17
CFLAGS          := -fPIC -fno-common
CXXFLAGS        := -fPIC -fno-common
LDFLAGS         := 
LDXXFLAGS       := -Lbuild -lcath
WARNINGS        := -Wall -Wextra -Wno-format-extra-args -Wpedantic -Wunused-value -Wunused-parameter -Wformat-zero-length -O3

#####################################
##            DIRECTORIES
#####################################

SRC_DIR         := src
TABLES_DIR      := inc/tables
C_FILES 		:= $(wildcard $(SRC_DIR)/*.c) 		\
        			$(wildcard $(SRC_DIR)/*/*.c) 	\
        		    $(wildcard $(SRC_DIR)/*/*/*.c) 	\
        		    $(wildcard $(TABLES_DIR)/*.c)
H_FILES         := $(wildcard inc/*.h) \
                   $(wildcard inc/enums/*.h) \
                   $(wildcard inc/instructions/*.h) \
                   $(wildcard inc/tables/*.h)
INC_FILES       := $(wildcard inc/tables/*.inc)

O_FILES 		:= $(patsubst $(SRC_DIR)/%.c,build/%.o,$(filter $(SRC_DIR)/%.c,$(C_FILES))) \
        		   $(patsubst $(SRC_DIR)/%,build/%,$(patsubst %.c,%.o,$(filter $(SRC_DIR)/%/*.c,$(C_FILES)))) \
        		   $(patsubst $(SRC_DIR)/%,build/%,$(patsubst %.c,%.o,$(filter $(SRC_DIR)/*/*/*.c,$(C_FILES)))) \
        		   $(patsubst $(TABLES_DIR)/%.c,build/tables_%.o,$(filter $(TABLES_DIR)/%.c,$(C_FILES)))

SRCX_DIR        := cplusplus/src
CXX_FILES       := $(wildcard $(SRCX_DIR)/*.cpp) $(wildcard $(SRCX_DIR)/*/*.cpp)
HXX_FILES       := $(wildcard cplusplus/inc/*.hpp) \
                   $(wildcard cplusplus/inc/instructions/*.hpp) \
                   $(wildcard cplusplus/inc/enums/*.hpp)
OXX_FILES       := $(patsubst $(SRCX_DIR)/%.cpp,build/cxx/%.o,$(CXX_FILES))

#####################################
##              TARGETS
#####################################

.PHONY: all clean dirs cxx

all: dirs build/libcath.a build/libcath.so build/catherine

cxx: dirs build/libcath.a build/libcath.so build/cathcxx

dirs:
	@mkdir -p build/instructions
	@mkdir -p build/instructions/DSP
	@mkdir -p build/cxx/instructions

build/%.o: $(SRC_DIR)/%.c $(H_FILES) $(INC_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $<

build/instructions/%.o: $(SRC_DIR)/instructions/%.c $(H_FILES) $(INC_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $<

build/tables_%.o: $(TABLES_DIR)/%.c $(H_FILES) $(INC_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $<

build/instructions/DSP/%.o: $(SRC_DIR)/instructions/DSP/%.c $(H_FILES) $(INC_FILES)
	$(CC) -c $(CSTD) $(IINC) $(WARNINGS) $(CFLAGS) -o $@ $<

build/cxx/%.o: $(SRCX_DIR)/%.cpp $(HXX_FILES)
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXX_STD) $(IINC_XX) $(WARNINGS) $(CXXFLAGS) -o $@ $<

build/cxx/instructions/%.o: $(SRCX_DIR)/instructions/%.cpp $(HXX_FILES)
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXX_STD) $(IINC_XX) $(WARNINGS) $(CXXFLAGS) -o $@ $<

build/libcath.a: $(O_FILES)
	$(AR) rcs $@ $^

build/libcath.so: build/libcath.a
	$(CC) -shared -o $@ -Wl,--whole-archive $< -Wl,--no-whole-archive

build/libcathcxx.a: $(OXX_FILES)
	$(AR) rcs $@ $^

build/catherine: $(O_FILES)
	$(CC) $^ $(LDFLAGS) -o $@

build/cathcxx: $(OXX_FILES) build/libcath.a
	$(CXX) $(OXX_FILES) $(LDXXFLAGS) -o $@

clean:
	rm -rf build
