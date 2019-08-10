CXX = g++

# GTEST_DIR needs to be set in bashrc using:
# export GTEST_DIR=<path to GTEST_DIR>
# on my linux machine: 
# /home/mengwen/Desktop/googletest-master/
# on my mac machine:
# /Users/mli/Desktop/gtest/googletest

TEST_OBJ_DIR = ./obj
TEST_SRC_DIR = .

ifndef HEADER_DIR
	HEADER_DIR = ../ ../../utils
endif

ifndef SRC_OBJ_DIR
	SRC_OBJ_DIR = ../obj
endif

# source files and headers.
TEST_SRC_FILES = $(notdir $(wildcard $(TEST_SRC_DIR)/*.cpp))

TEST_OBJ_FILES := $(addprefix $(TEST_OBJ_DIR)/, $(TEST_SRC_FILES:.cpp=.o))
SRC_OBJ_FILES = $(wildcard $(SRC_OBJ_DIR)/*.o)
SRC_OBJ_FILES := $(filter-out $(SRC_OBJ_DIR)/main.o,$(SRC_OBJ_FILES))

TEST_DEP_FILES = $(TEST_OBJ_FILES:.o=.d)

CPP_FLAGS += -isystem $(GTEST_DIR)/googlemock/include
CXX_FLAGS += -g -Wall -Wextra -pthread -std=c++11
CXX_FLAGS += $(foreach d, $(HEADER_DIR), -I$d)
CXX_FLAGS += -I$(GTEST_DIR)/googlemock/include -I$(GTEST_DIR)/googletest/include

# CXX_FLAGS += -Wno-unused-parameter -Wno-unused-variable -Wno-unused-private-field
LD_FLAGS = -lpthread

GMOCK_LIB_MAIN = $(GTEST_DIR)/googlemock/make/gmock_main.a

.PHONY: libgmock clean

all_tests: $(TEST_OBJ_FILES) $(SRC_OBJ_FILES)
	$(MAKE) libgmock
	$(MAKE) -C .. main
	$(CXX) $(CPP_FLAGS) $(CXX_FLAGS) $(LD_FLAGS) $^ $(GMOCK_LIB_MAIN) -o $@ 

libgmock:
	$(MAKE) -C $(GTEST_DIR)/googlemock/make/

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp
	$(CXX) -MMD -MP -MF $(@:.o=.d) -MT $@ -c $(CPP_FLAGS) $(CXX_FLAGS) $< -o $@

clean:
	@rm $(TEST_OBJ_DIR)/*.o $(TEST_OBJ_DIR)/*.a 2>/dev/null || true 
	@rm all_tests 2>/dev/null || true 

$(TEST_OBJ_FILES): | $(TEST_OBJ_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

-include $(TEST_DEP_FILES)