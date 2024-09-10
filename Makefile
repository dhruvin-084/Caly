PRODUCT := caly
BINDIR := build
INCDIR := include
SRCDIR := src
OBJDIR := build

CXX := g++
LINKER := g++
INCDIRS := -I$(INCDIR)
CXXFLAGS := -std=c++11 -Wall -Wextra

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))
DEPFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(SRCFILES))

$(BINDIR)/$(PRODUCT): $(OBJFILES)
	$(LINKER) $(CXXFLAGS) $^ -o $@ 

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@ 

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp 
	$(CXX) $(INCDIRS) -MM $< \
		| sed -e 's%^%$@ %' -e 's% % $(OBJDIR)/%'\ > $@

clean:
	rm build/*

-include $(DEPFILES)