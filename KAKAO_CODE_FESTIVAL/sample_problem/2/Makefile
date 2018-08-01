TARGET = main.py

INPUT := input.txt
OUTPUT := output.txt
MYOUT := myout.txt



.PHONY: test
test:
	python3 $(TARGET)

.PHONY: in
in:
	python3 $(TARGET) < $(INPUT)

.PHONY: out
out:
	python3 $(TARGET) < $(INPUT) > $(MYOUT)


.PHONY: diff
diff: clean
	pyton3 $(TARGET) < $(INPUT) > $(MYOUT)
	diff $(OUTPUT) $(MYOUT)


# Delete binary & object files.
clean:
	$(RM) $(MYOUT)
