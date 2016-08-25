CXX = g++
#OBJSSUM = summation.o
#SRCSSUM = summation.cpp
#OBJSAVG = average.o
#SRCSAVG = average.cpp
OBJSL1 = InputValid.o
SRCSL1 = InputValid.cpp
OBJSL2 = main.o
SRCSL2 = main.cpp
HEADERS = summation.hpp
HEADERA = average.hpp
HEADERI = InputValid.hpp
PROG = LabE
all: $(PROG)

$(PROG): $(OBJSL2) $(OBJSL1)
	$(CXX) $(OBJSL2) $(OBJSL1) -o $(PROG)
$(OBJSL2): $(SRCSL2) $(HEADERI) 
	$(CXX) -c $(SRCSL2)
#average.o: $(SCRSAVG) $(HEADERA) 
#	$(CXX) -c $(SRCSAVG)
InputValid.o: $(SRCSL1) $(HEADERI)
	$(CXX) -c $(SRCSL1)
#summation.o: $(SRCSSUM) $(HEADERS)
#	$(CXX) -c $(SRCSSUM)
clean:
	rm -rf *.o $(PROG) 
