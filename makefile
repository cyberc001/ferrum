CC = gcc -g
LIBS = -I./libdiscord/lib -I./libdiscord -L./libdiscord -ldiscord -lcurl

ferrum: main.o fe_client.o fe_config.o fe_chatter.o fe_command.o
	$(CC) main.o fe_client.o fe_config.o fe_chatter.o fe_command.o -o ferrum $(LIBS)

main.o:
	$(CC) -c main.c $(LIBS)

fe_client.o:
	$(CC) -c fe_client.c $(LIBS)
fe_config.o:
	$(CC) -c fe_config.c $(LIBS)
fe_chatter.o:
	$(CC) -c fe_chatter.c $(LIBS)
fe_command.o:
	$(CC) -c fe_command.c $(LIBS)

clean:
	rm *.o
	rm ferrum
