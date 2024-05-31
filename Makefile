CC := gcc
SRCDIR := src
BUILDDIR := build
TARGET := bin/meltwing
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -Wall -pedantic -Werror -g -ggdb -Wextra
LIB := -lgit2
INC := -I include
LT := clang-tidy
FT := clang-format 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(dir $@)
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB) -O3

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " Building..."
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $< -save-temps -O3

exe: $(TARGET)
	@echo "Execute the Meltwing"
	@echo ""
	@./bin/meltwing -h
linter:
	@$(LT) src/*.c
format:
	@$(FT) -i src/*.c
install: $(TARGET)
	@echo "Install The CLI"
	@sudo cp ./bin/meltwing /usr/bin/
uninstall:
	@echo "Uninstall the CLI"
	@sudo rm /usr/bin/meltwing

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
# tester:
# 	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# # Spikes
# ticket:
# 	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean all
