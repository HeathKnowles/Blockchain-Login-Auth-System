CC=gcc
CFLAGS=-Wall -Wextra -I.
LIBS=-lssl -lcrypto

# Updated dependencies and object files
DEPS=structures.h blockchain.h user_management.h password_security.h crypto_utils.h terminal_ui.h
OBJ=main.o blockchain.o user_management.o password_security.o crypto_utils.o terminal_ui.o

# Default target
all: secure_login

# Pattern rule for object files
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Link the final executable
secure_login: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Clean target
.PHONY: clean
clean:
	rm -f *.o secure_login
	rm -rf users.dat