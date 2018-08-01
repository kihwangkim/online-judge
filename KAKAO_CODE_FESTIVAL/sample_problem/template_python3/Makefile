TARGET = main.py



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
	python3 $(TARGET) < $(INPUT) > $(MYOUT)
	diff $(OUTPUT) $(MYOUT)


# Delete binary & object files.
clean:
	$(RM) $(MYOUT)
