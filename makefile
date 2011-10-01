
all:
	gcc -g ChordLib.c -lpthread -c
	gcc -g -o peer Peer.c -lpthread ChordLib.o 
	gcc -g -o peerZero PeerZero.c -lpthread ChordLib.o
	gcc -lpthread -o sendHome SendHome.c ChordLib.o 
clean:
	rm *.o peer peerZero
