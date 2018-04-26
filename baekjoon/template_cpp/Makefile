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
run: $(TARGET)
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


# Delete binary & object files.
clean:
	$(RM) $(TARGET) $(MYOUT)
