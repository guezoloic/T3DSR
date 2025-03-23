NME = $(shell uname)

EXE = t3dsr
TXE = t3dsr_test

INC = include
SRC = src
TST = test
BLD = build

DIR = $(BLD)/debug
TDR = $(BLD)/test

CC = clang 
CFLAGS = -Wall -Wextra -I$(INC) -g
LDFLAGS = 

SRCS := $(shell find $(SRC) -name "*.c")
OBJS := $(SRCS:$(SRC)/%.c=$(DIR)/%.o)

ifeq ($(NME), Darwin)
	LDFLAGS += -ObjC -framework Foundation -framework Metal
	MSRCS += $(shell find $(SRC) -name "*.m")
	SRCS += $(MSRCS)
	OBJS += $(MSRCS:$(SRC)/%.m=$(DIR)/%.o)
endif

.PHONY: all clean run test debug
all: $(EXE)

$(EXE): $(OBJS) | $(DIR)
	@$(CC) $(CFLAGS) $^ -o $(BLD)/$@ $(LDFLAGS)

$(DIR):
	@mkdir -p $(DIR)

$(DIR)/%.o: $(SRC)/%.c | $(DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIR)/%.o: $(SRC)/%.m | $(DIR)
	@mkdir -p $(dir $@)
	@$(CC) -x objective-c $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BLD) $(EXE) $(TXE)

run: $(EXE)
	@./$(BLD)/$(EXE)

TSRCS := $(shell find $(TST) -name "*.c")
TOBJS := $(TSRCS:$(TST)/%.c=$(TDR)/%.o) \
	$(filter-out $(DIR)/main.o, $(OBJS))

debug:
	@echo "SRCS : $(SRCS)"
	@echo "TSRCS: $(TSRCS)"
	@echo "OBJS : $(OBJS)"
	@echo "TOBJS: $(TOBJS)"

$(TDR)/%.o: $(TST)/%.c | $(TDR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(TDR):
	@mkdir -p $(TDR)

$(TXE): $(TOBJS) | $(TDR) $(DIR)
	@$(CC) $^ -o $(BLD)/$@ $(LDFLAGS)

test: $(TXE)
	@./$(BLD)/$(TXE)