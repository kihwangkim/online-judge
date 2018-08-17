CC = g++
CXXFLAGS = -g -O2 -std=c++11 -static
TARGET = a.out

SRCS := main.cpp
INPUT := input.txt
OUTPUT := output.txt
MYOUT := myout.txt


$(TARGET): clean
	$(CC) $(CXXFLAGS) $(SRCS) -o $(TARGET)


.PHONY: test
test: $(TARGET)
	./$(TARGET)

.PHONY: in
in: $(TARGET)
	./$(TARGET) < $(INPUT)

.PHONY: out
out: $(TARGET)
	./$(TARGET) < $(INPUT) > $(MYOUT)


.PHONY: diff
diff: clean $(TARGET)
	./$(TARGET) < $(INPUT) > $(MYOUT)
	diff $(OUTPUT) $(MYOUT)

.PHONY: 1
1: $(TARGET)
	./$(TARGET) < input1.txt

.PHONY: 2
2: $(TARGET)
	./$(TARGET) < input2.txt

.PHONY: 3
3: $(TARGET)
	./$(TARGET) < input3.txt

.PHONY: 4
4: $(TARGET)
	./$(TARGET) < input4.txt

.PHONY: 5
5: $(TARGET)
	./$(TARGET) < input5.txt

.PHONY: 6
6: $(TARGET)
	./$(TARGET) < input6.txt

.PHONY: 7
7: $(TARGET)
	./$(TARGET) < input7.txt




# Delete binary & object files.
clean:
	$(RM) $(TARGET) $(MYOUT)
