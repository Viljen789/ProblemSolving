cmake_minimum_required(VERSION 3.29)
project(ProblemSolving)

set(CMAKE_CXX_STANDARD 14)

include_directories(NIO)
include_directories(NIO/NIO)

add_executable(ProblemSolving
    "Algoritmer++/2022-2 2.cpp"
    Algoritmer++/2022-2.cpp
    "Algoritmer++/anothaOne 2.cpp"
    Algoritmer++/anothaOne.cpp
    "Algoritmer++/BST 2.cpp"
    Algoritmer++/BST.cpp
    "Algoritmer++/Dijk 2.cpp"
    Algoritmer++/Dijk.cpp
    "Algoritmer++/Dijkstra 2.cpp"
    Algoritmer++/Dijkstra.cpp
    "Algoritmer++/Djirk 2.cpp"
    Algoritmer++/Djirk.cpp
    "Algoritmer++/lenstr 2.cpp"
    Algoritmer++/lenstr.cpp
    "Algoritmer++/newlabsearch 2.cpp"
    Algoritmer++/newlabsearch.cpp
    "Algoritmer++/OnesAndZeros 2.cpp"
    Algoritmer++/OnesAndZeros.cpp
    "Algoritmer++/SepStr 2.cpp"
    Algoritmer++/SepStr.cpp
    "Algoritmer++/str(n)cpy 2.cpp"
    "Algoritmer++/str(n)cpy.cpp"
    "Algoritmer++/Swap 2.cpp"
    Algoritmer++/Swap.cpp
    "Algoritmer++/test 2.cpp"
    Algoritmer++/test.cpp
    "Algoritmer++/UnionFind 2.cpp"
    Algoritmer++/UnionFind.cpp
    "Algoritmer++/VectorLabyrinth 2.cpp"
    Algoritmer++/VectorLabyrinth.cpp
    "AOC/1 2.cpp"
    AOC/1.cpp
    "AOC/4 2.cpp"
    AOC/4.cpp
    "AOC/5 2.cpp"
    AOC/5.cpp
    "AOC/5v2 2.cpp"
    AOC/5v2.cpp
    "AOC/6 2.cpp"
    AOC/6.cpp
    "AOC/7 2.cpp"
    AOC/7.cpp
    "AOC/8 2.cpp"
    AOC/8.cpp
    "AOC/test 2.cpp"
    AOC/test.cpp
    "Compp/ATC313/1904A 2.cpp"
    Compp/ATC313/1904A.cpp
    "Compp/ATC313/A 2.cpp"
    Compp/ATC313/A.cpp
    "Compp/ATC313/ABC300A 2.cpp"
    Compp/ATC313/ABC300A.cpp
    "Compp/ATC313/B 2.cpp"
    Compp/ATC313/B.cpp
    "Compp/ATC313/C 2.cpp"
    Compp/ATC313/C.cpp
    "Compp/ATC313/D 2.cpp"
    Compp/ATC313/D.cpp
    "Compp/Educative/Combin 2.cpp"
    Compp/Educative/Combin.cpp
    "Compp/Educative/map 2.cpp"
    Compp/Educative/map.cpp
    "Compp/Educative/Primes 2.cpp"
    Compp/Educative/Primes.cpp
    "Compp/NIOoppgaver/blippcoin 2.cpp"
    Compp/NIOoppgaver/blippcoin.cpp
    "Compp/NIOoppgaver/glomma 2.cpp"
    Compp/NIOoppgaver/glomma.cpp
    "Compp/NIOoppgaver/kuponger 2.cpp"
    Compp/NIOoppgaver/kuponger.cpp
    "Compp/NIOoppgaver/nio16-runde2-lavalek 2.cpp"
    Compp/NIOoppgaver/nio16-runde2-lavalek.cpp
    "Compp/NIOoppgaver/nio16-runde2-tannhjul 2.cpp"
    Compp/NIOoppgaver/nio16-runde2-tannhjul.cpp
    "Compp/NIOoppgaver/test 2.cpp"
    Compp/NIOoppgaver/test.cpp
    "Compp/NIOoppgaver/testcoordtoadjl 2.cpp"
    Compp/NIOoppgaver/testcoordtoadjl.cpp
    "Compp/NIOoppgaver/vann 2.cpp"
    Compp/NIOoppgaver/vann.cpp
    "Compp/11292 2.cpp"
    Compp/11292.cpp
    "Compp/1594A 2.cpp"
    Compp/1594A.cpp
    "Compp/1809A 2.cpp"
    Compp/1809A.cpp
    "Compp/1829A 2.cpp"
    Compp/1829A.cpp
    "Compp/1832A 2.cpp"
    Compp/1832A.cpp
    "Compp/1832B 2.cpp"
    Compp/1832B.cpp
    "Compp/1837A 2.cpp"
    Compp/1837A.cpp
    "Compp/1837B 2.cpp"
    Compp/1837B.cpp
    "Compp/1846A 2.cpp"
    Compp/1846A.cpp
    "Compp/1846B 2.cpp"
    Compp/1846B.cpp
    "Compp/1846C 2.cpp"
    Compp/1846C.cpp
    "Compp/1846D 2.cpp"
    Compp/1846D.cpp
    "Compp/1847A 2.cpp"
    Compp/1847A.cpp
    "Compp/1847B 2.cpp"
    Compp/1847B.cpp
    "Compp/1860C 2.cpp"
    Compp/1860C.cpp
    "Compp/1A 2.cpp"
    Compp/1A.cpp
    "Compp/231A 2.cpp"
    Compp/231A.cpp
    "Compp/dekoding 2.cpp"
    Compp/dekoding.cpp
    "Compp/NIO14R2Brodering 2.cpp"
    Compp/NIO14R2Brodering.cpp
    "Compp/primtal 2.cpp"
    Compp/primtal.cpp
    "Compp/SmallestTrioUdemy 2.cpp"
    Compp/SmallestTrioUdemy.cpp
    "Compp/usacotest 2.cpp"
    Compp/usacotest.cpp
    "CP/GFG/add_ones 2.cpp"
    CP/GFG/add_ones.cpp
    "CP/GFG/mergesort 2.cpp"
    CP/GFG/mergesort.cpp
    "CP/GFG/ropecutting 2.cpp"
    CP/GFG/ropecutting.cpp
    "CP/NIO/937A 2.cpp"
    CP/NIO/937A.cpp
    "CP/NIO/937B 2.cpp"
    CP/NIO/937B.cpp
    "CP/NIO/937C 2.cpp"
    CP/NIO/937C.cpp
    "CP/NIO/937D 2.cpp"
    CP/NIO/937D.cpp
    "CP/NIO/937E 2.cpp"
    CP/NIO/937E.cpp
    "CP/NIO/brack 2.cpp"
    CP/NIO/brack.cpp
    "CP/NIO/dice 2.cpp"
    CP/NIO/dice.cpp
    "CP/NIO/mincoins 2.cpp"
    CP/NIO/mincoins.cpp
    "CP/NIO/mino 2.cpp"
    CP/NIO/mino.cpp
    "CP/NIO/minot 2.cpp"
    CP/NIO/minot.cpp
    "CP/NIO/Rektangelrot 2.cpp"
    CP/NIO/Rektangelrot.cpp
    "CP/NIO/rektøv 2.cpp"
    CP/NIO/rektøv.cpp
    "CP/NIO/rett 2.cpp"
    CP/NIO/rett.cpp
    "CP/NIO/rettf 2.cpp"
    CP/NIO/rettf.cpp
    "CP/NIO/rettferdig 2.cpp"
    CP/NIO/rettferdig.cpp
    "CP/NIO/rettferdighet 2.cpp"
    CP/NIO/rettferdighet.cpp
    "CP/NIO/rettmedneg 2.cpp"
    CP/NIO/rettmedneg.cpp
    "CP/NIO/rettutenneg 2.cpp"
    CP/NIO/rettutenneg.cpp
    "CP/NIO/temp 2.cpp"
    CP/NIO/temp.cpp
    "CP/NIO/test 2.cpp"
    CP/NIO/test.cpp
    CP/Prac/CSES/add_ones.cpp
    CP/Prac/CSES/equilibrium.cpp
    CP/Prac/CSES/Jose2.cpp
    "CP/Prac/1428B 2.cpp"
    CP/Prac/1428B.cpp
    "CP/Prac/1428C 2.cpp"
    CP/Prac/1428C.cpp
    "CP/Prac/1904A 2.cpp"
    CP/Prac/1904A.cpp
    "CP/Prac/1928A 2.cpp"
    CP/Prac/1928A.cpp
    "CP/Prac/1928B 2.cpp"
    CP/Prac/1928B.cpp
    "CP/Prac/1950E 2.cpp"
    CP/Prac/1950E.cpp
    "CP/Prac/2014C 2.cpp"
    CP/Prac/2014C.cpp
    "CP/Prac/2020A 2.cpp"
    CP/Prac/2020A.cpp
    "CP/Prac/2020B 2.cpp"
    CP/Prac/2020B.cpp
    "CP/Prac/2020C 2.cpp"
    CP/Prac/2020C.cpp
    "CP/Prac/37per 2.cpp"
    CP/Prac/37per.cpp
    "CP/Prac/701C 2.cpp"
    CP/Prac/701C.cpp
    "CP/Prac/A 2.cpp"
    CP/Prac/A.cpp
    "CP/Prac/agc066A 2.cpp"
    CP/Prac/agc066A.cpp
    "CP/Prac/agc066C 2.cpp"
    CP/Prac/agc066C.cpp
    "CP/Prac/agc066D 2.cpp"
    CP/Prac/agc066D.cpp
    "CP/Prac/agc066E 2.cpp"
    CP/Prac/agc066E.cpp
    "CP/Prac/test 2.cpp"
    CP/Prac/test.cpp
    "CP/VIM/test 2.cpp"
    CP/VIM/test.cpp
    "LeetCodeØving/LeetCodeØving/leap 2.cpp"
    LeetCodeØving/LeetCodeØving/leap.cpp
    "LeetCodeØving/LeetCodeØving/main 2.cpp"
    LeetCodeØving/LeetCodeØving/main.cpp
        LeetCodeØving/mergesorted.cpp
    "LeetCodeØving/tip 2.cpp"
    LeetCodeØving/tip.cpp
    "LeetCodeØving/twosum 2.cpp"
    LeetCodeØving/twosum.cpp
    NCPC/2023/A.cpp
    "NIO/NIO/BackUp 2.cpp"
    NIO/NIO/BackUp.cpp
    "NIO/NIO/main 2.cpp"
    NIO/NIO/main.cpp
    "NIO/NIO/newtestlabyrinth 2.cpp"
    NIO/NIO/newtestlabyrinth.cpp
    "NIO/NIO/newting 2.cpp"
    NIO/NIO/newting.cpp
    "NIO/NIO/sick 2.cpp"
    NIO/NIO/sick.cpp
    "NIO/NIO/SickPeople2022-2 2.cpp"
    NIO/NIO/SickPeople2022-2.cpp
    "NIO/NIO/tester 2.cpp"
    NIO/NIO/tester.cpp
    "NIO/NIO/Tester2 2.cpp"
    "NIO/NIO/Tester2 2.hpp"
    NIO/NIO/Tester2.cpp
    NIO/NIO/Tester2.hpp
    "NIO/Header 2.h"
    NIO/Header.h
    "NIO/Testing 2.cpp"
    "NIO/Testing 2.hpp"
    NIO/Testing.cpp
    NIO/Testing.hpp
    "NIO - Copy/base 2.cpp"
    "NIO - Copy/base 3.cpp"
    "NIO - Copy/base 4.cpp"
    "NIO - Copy/base.cpp"
    "NIO - Copy/basebs 2.cpp"
    "NIO - Copy/basebs 3.cpp"
    "NIO - Copy/basebs 4.cpp"
    "NIO - Copy/basebs.cpp"
    "NIO - Copy/basehopp 2.cpp"
    "NIO - Copy/basehopp 3.cpp"
    "NIO - Copy/basehopp 4.cpp"
    "NIO - Copy/basehopp.cpp"
    "NIO - Copy/bh 2.cpp"
    "NIO - Copy/bh 3.cpp"
    "NIO - Copy/bh 4.cpp"
    "NIO - Copy/bh.cpp"
    "NIO - Copy/debtog 2.cpp"
    "NIO - Copy/debtog 3.cpp"
    "NIO - Copy/debtog 4.cpp"
    "NIO - Copy/debtog.cpp"
    "NIO - Copy/ikkjeendre 2.cpp"
    "NIO - Copy/ikkjeendre 3.cpp"
    "NIO - Copy/ikkjeendre 4.cpp"
    "NIO - Copy/ikkjeendre.cpp"
    "NIO - Copy/mino 2.cpp"
    "NIO - Copy/mino 3.cpp"
    "NIO - Copy/mino 4.cpp"
    "NIO - Copy/mino.cpp"
    "NIO - Copy/minotaur 2.cpp"
    "NIO - Copy/minotaur 3.cpp"
    "NIO - Copy/minotaur 4.cpp"
    "NIO - Copy/minotaur.cpp"
    "NIO - Copy/optimtog 2.cpp"
    "NIO - Copy/optimtog 3.cpp"
    "NIO - Copy/optimtog 4.cpp"
    "NIO - Copy/optimtog.cpp"
    "NIO - Copy/r 2.cpp"
    "NIO - Copy/r 3.cpp"
    "NIO - Copy/r 4.cpp"
    "NIO - Copy/r.cpp"
    "NIO - Copy/rekt 2.cpp"
    "NIO - Copy/rekt 3.cpp"
    "NIO - Copy/rekt 4.cpp"
    "NIO - Copy/rekt.cpp"
    "NIO - Copy/rett 2.cpp"
    "NIO - Copy/rett 3.cpp"
    "NIO - Copy/rett 4.cpp"
    "NIO - Copy/rett.cpp"
    "NIO - Copy/rettferdighet 2.cpp"
    "NIO - Copy/rettferdighet 3.cpp"
    "NIO - Copy/rettferdighet 4.cpp"
    "NIO - Copy/rettferdighet.cpp"
    "NIO - Copy/spesielleTall 2.cpp"
    "NIO - Copy/spesielleTall 3.cpp"
    "NIO - Copy/spesielleTall 4.cpp"
    "NIO - Copy/spesielleTall.cpp"
    "NIO - Copy/test 2.cpp"
    "NIO - Copy/test 3.cpp"
    "NIO - Copy/test 4.cpp"
    "NIO - Copy/test.cpp"
    "NIO - Copy/testerny 2.cpp"
    "NIO - Copy/testerny 3.cpp"
    "NIO - Copy/testerny 4.cpp"
    "NIO - Copy/testerny.cpp"
    "NIO - Copy/tog 2.cpp"
    "NIO - Copy/tog 3.cpp"
    "NIO - Copy/tog 4.cpp"
    "NIO - Copy/tog.cpp"
    "NIO - Copy/tognett 2.cpp"
    "NIO - Copy/tognett 3.cpp"
    "NIO - Copy/tognett 4.cpp"
    "NIO - Copy/tognett.cpp"
    "NIO.cpp/NIO.cpp/main 2.cpp"
    NIO.cpp/NIO.cpp/main.cpp
    "OL/OL/main 2.cpp"
    OL/OL/main.cpp
    "OppgaverNIO/bananbonanza (1) 2.cpp"
    "OppgaverNIO/bananbonanza (1).cpp"
    "OppgaverNIO/Bananbonanza 2.cpp"
    OppgaverNIO/Bananbonanza.cpp
    "OppgaverNIO/BananbonanzaT 2.cpp"
    OppgaverNIO/BananbonanzaT.cpp
    "OppgaverNIO/GK 2.cpp"
    OppgaverNIO/GK.cpp
    "OppgaverNIO/Lynnedslag 2.cpp"
    "OppgaverNIO/Lynnedslag-test 2.cpp"
    OppgaverNIO/Lynnedslag-test.cpp
    OppgaverNIO/Lynnedslag.cpp
    "OppgaverNIO/nettverkssikkerhet 2.cpp"
    OppgaverNIO/nettverkssikkerhet.cpp
    "OppgaverNIO/nettverkssikkerhetfil 2.cpp"
    OppgaverNIO/nettverkssikkerhetfil.cpp
    "OppgaverNIO/NS 2.cpp"
    OppgaverNIO/NS.cpp
    "OppgaverNIO/Personlighetstyper 2.cpp"
    OppgaverNIO/Personlighetstyper.cpp
    "OppgaverNIO/tns 2.cpp"
    OppgaverNIO/tns.cpp
    projects/Advent/Advent1.cpp
    projects/Advent/Advent10.cpp
    projects/Advent/Advent11.cpp
    projects/Advent/Advent2.cpp
    projects/Advent/Advent3.cpp
    projects/Advent/Advent4.cpp
    projects/Advent/Advent5.cpp
    projects/Advent/Advent6.cpp
    projects/Advent/Advent7.cpp
    projects/Advent/Advent8.cpp
    projects/Advent/Advent9.cpp
    projects/Advent/Advent_template.cpp
    projects/Advent/pointers.cpp
    projects/Advent/test.cpp
    projects/Advent/test2.cpp
    "Tilfeldige oppgaver/tip 2.cpp"
    "Tilfeldige oppgaver/tip.cpp"
        LeetCodeØving/mergelinkedlist.cpp
        LeetCodeØving/test.cpp
)
