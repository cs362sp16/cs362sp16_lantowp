CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

adventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c adventurer.c rngs.c -o randomtestadventurer -lm -g

runAdventurer: adventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomcard:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g

runRandomCard: randomcard
	./randomtestcard &> randomtestcard.out
	gcov dominion.c >> randomtestcard.out
	cat dominion.c.gcov >> randomcard.out

randomtesting:
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard.c rngs.c -o randomtestcard -lm -g
	./randomtestcard >> randomtestcard.out
	gcov dominion.c >> randomtestcard.out

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

playdom2: dominion.o playdom2.c
	gcc -o playdom2 playdom2.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unit3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g


myTest:
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g
	./unittest1 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g
	./unittest2 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g
	./unittest3 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g
	./unittest4 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g
	./cardtest1 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g
	./cardtest2 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g
	./cardtest3 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g
	./cardtest4 1 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

tarantulaTest:
	rm -f dominion.c.gcov dominion.gcda dominion.gcno unit_test1.out tarantula.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test1.c rngs.c -o unittest1 -lm -g
	./unittest1 1 >> unit_test1.out
	gcov dominion.c
	cat dominion.c.gcov >> unit_test1.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno unit_test2.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test2.c rngs.c -o unittest2 -lm -g
	./unittest2 1 >> unit_test2.out
	gcov dominion.c
	cat dominion.c.gcov >> unit_test2.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno unit_test3.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test3.c rngs.c -o unittest3 -lm -g
	./unittest3 1 >> unit_test3.out
	gcov dominion.c
	cat dominion.c.gcov >> unit_test3.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno unit_test4.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unit_test4.c rngs.c -o unittest4 -lm -g
	./unittest4 1 >> unit_test4.out
	gcov dominion.c
	cat dominion.c.gcov >> unit_test4.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno card_test1.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test1.c rngs.c -o cardtest1 -lm -g
	./cardtest1 1 >> card_test1.out
	gcov dominion.c
	cat dominion.c.gcov >> card_test1.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno card_test2.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test2.c rngs.c -o cardtest2 -lm -g
	./cardtest2 1 >> card_test2.out
	gcov dominion.c
	cat dominion.c.gcov >> card_test2.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno card_test3.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test3.c rngs.c -o cardtest3 -lm -g
	./cardtest3 1 >> card_test3.out
	gcov dominion.c
	cat dominion.c.gcov >> card_test3.out
	rm -f dominion.c.gcov dominion.gcda dominion.gcno card_test4.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c card_test4.c rngs.c -o cardtest4 -lm -g
	./cardtest4 1 >> card_test4.out
	gcov dominion.c
	cat dominion.c.gcov >> card_test4.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

testdominion: dominion.o interface.o testdominion.c
	rm -f dominion.c.gcov dominion.gcda dominion.gcno gameResults.out testdominion.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testdominion.c interface.c rngs.c -o testdominion -lm -g
	./testdominion 1 >> gameResults.out
	gcov dominion.c >> testdominion.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

go.o: dominion.h dominion.c rngs.o
	gcc dominion.c -g  $(CFLAGS)

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
