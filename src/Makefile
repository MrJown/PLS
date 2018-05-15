CC = gcc
OBJS = main.o lecture_traitement_fichier.o plus_petites_valeurs.o # Liste de tous les fichiers
CFLAGS = -I ../headers # Les .h ne sont pas dans le même dossier

all: main clean

# Creation de l'executable
main: $(OBJS)
		$(CC) $(OBJS) -o ../bin/$@ -lm -g

# Creation des objets
%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean :
		-rm -f *.o *~
