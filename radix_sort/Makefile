# Nom de l'exécutable
EXECUTABLE = main

# Compilateur à utiliser
CC = gcc

# Options de compilation (vous pouvez les personnaliser)
CFLAGS = -Wall -Wextra -g

# Liste de tous vos fichiers sources (.c)
SOURCES = $(wildcard *.c)

# Liste des fichiers objets (.o)
OBJECTS = $(SOURCES:.c=.o)

# Règle par défaut : compiler l'exécutable
all: $(EXECUTABLE)

# Règle pour compiler l'exécutable à partir des objets
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour compiler un fichier source en fichier objet
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Règle pour tout reconstruire (nettoyage + compilation)
rebuild: clean all

build-docker:
	docker build --platform linux/arm64 -t radix .

run-docker:
	docker run -it --rm -v $(PWD):/app --name my-running-app radix