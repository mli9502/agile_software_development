CXX = g++
LD_FLAGS = 
CXX_FLAGS = -std=c++11 -g

SRC_DIR = .
HEADER_DIR = . ../utils 
OBJ_DIR = ./obj

MAIN_CPP = ./main.cpp
MAIN_OBJ = ./main.o

CXX_FLAGS += $(foreach d, $(HEADER_DIR), -I$d)
# CXX_FLAGS += -Wall -Wno-unused-variable -Wno-format-security -Wno-sign-compare

SRC_FILES = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
OBJ_FILES := $(filter-out $(OBJ_DIR)/main.o,$(OBJ_FILES))
DEP_FILES = $(OBJ_FILES:.o=.d)

.PHONY: all main run clean

all: main

main: $(OBJ_FILES) $(MAIN_OBJ)
	$(CXX) -o $@ $^ $(LD_FLAGS)

run: main
	./main

$(MAIN_OBJ): $(MAIN_CPP)
	$(CXX) -MMD -MP -MF $(@:.o=.d) -MT $@ -c $(CXX_FLAGS) $< -o $@

# -MMD: No -E (only do preprocess) implied.
#       Meaning that dependency files are generated as a side effect.
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html
# http://scottmcpeak.com/autodepend/autodepend.html
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -MMD -MP -MF $(@:.o=.d) -MT $@ -c $(CXX_FLAGS) $< -o $@

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@rm main *.o $(OBJ_DIR)/*.o 2>/dev/null || true

-include $(DEP_FILES)
