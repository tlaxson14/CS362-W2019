CFLAGS= -Wall -fpic -coverage -lm -std=c99
GCOVFLAGS= -Wall -fpic -fprofile-arcs -ftest-coverage -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

cardtest1: cardtest1.c dominion.o rngs.o
	gcc $(CFLAGS) -o cardtest1 cardtest1.c -g dominion.o rngs.o
	./cardtest1 >> cardtest1results.out
	gcov cardtest1.c >> cardtest1results.out

cardtest1source: cardtest1.c rngs.o dominion.o
	gcc $(GCOVFLAGS) -c dominion.c -g
	gcc $(CFLAGS) -o cardtest1 cardtest1.c -g dominion.o rngs.o
	./cardtest1 >> cardtest1results.out
	gcov dominion.c >> cardtest1sourceresults.out

cardtest2: cardtest2.c dominion.o rngs.o
	gcc $(CFLAGS) -o cardtest2 cardtest2.c -g dominion.o rngs.o
	./cardtest2 >> cardtest2results.out
	gcov cardtest2.c >> cardtest2results.out

cardtest2source: cardtest2.c rngs.o dominion.o
	gcc $(GCOVFLAGS) -c dominion.c -g
	gcc $(CFLAGS) -o cardtest2 cardtest2.c -g dominion.o rngs.o
	./cardtest2 >> cardtest2results.out
	gcov dominion.c >> cardtest2sourceresults.out

cardtest3: cardtest3.c dominion.o rngs.o
	gcc $(CFLAGS) -o cardtest3 cardtest3.c -g dominion.o rngs.o
	./cardtest3 >> cardtest3results.out
	gcov cardtest3.c >> cardtest3results.out

cardtest3source: cardtest3.c rngs.o dominion.o
	gcc $(GCOVFLAGS) -c dominion.c -g
	gcc $(CFLAGS) -o cardtest3 cardtest3.c -g dominion.o rngs.o
	./cardtest3 >> cardtest3results.out
	gcov dominion.c >> cardtest3sourceresults.out

cardtest4: cardtest4.c dominion.o rngs.o
	gcc $(CFLAGS) -o cardtest4 cardtest4.c -g dominion.o rngs.o
	./cardtest4 >> cardtest4results.out
	gcov cardtest4.c >> cardtest4results.out

cardtest4source: cardtest4.c rngs.o dominion.o
	gcc $(GCOVFLAGS) -c dominion.c -g
	gcc $(CFLAGS) -o cardtest4 cardtest4.c -g dominion.o rngs.o
	./cardtest4 >> cardtest4results.out
	gcov dominion.c >> cardtest4sourceresults.out

unittestresults.out: dominion.o rngs.o cardtest1.c
	gcc $(GCOVFLAGS) -c dominion.c -g
	gcc $(CFLAGS) -o unittest4 unittest4.c -g dominion.o rngs.o
	./unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out

randomtestcard1: randomtestcard1.c rngs.o dominion.o
	gcc $(CFLAGS) -o randomtestSmithycard1 randomtestcard1.c -g dominion.o rngs.o

randomtestcard1.out: randomtestSmithycard1
	gcc $(CFLAGS) -o randomtestSmithycard1 randomtestcard1.c -g dominion.o rngs.o
	./randomtestSmithycard1 >> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	
randomtestcard2: randomtestcard2.c rngs.o dominion.o
	gcc $(CFLAGS) -o randomtestVillagecard2 randomtestcard2.c -g dominion.o rngs.o

randomtestcard2.out: randomtestVillagecard2
	gcc $(CFLAGS) -o randomtestVillagecard2 randomtestcard2.c -g dominion.o rngs.o
	./randomtestVillagecard2 >> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out

randomtestadventurer: randomtestadventurer.c rngs.o dominion.o
	gcc $(CFLAGS) -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o

randomtestadventurer.out: randomtestadventurer
	gcc $(CFLAGS) -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o
	./randomtestadventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c >> randomtestadventurer.out

randomsourcetest: randomtestadventurer
	gcc $(CFLAGS) -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o
	gcc $(GCOVFLAGS) -c dominion.c -g
	./randomtestadventurer >> randomtestsourceresults.out
	gcov dominion.c >> randomtestsourceresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 testDrawCard testDrawCard.exe randomSmithyCardTest1
