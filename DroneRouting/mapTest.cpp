#include "mapTest.h"
#include "Graph.h"
#include "Waypoints.h"
#include "RouteFinder.h"
#include "HaversineScorer.h"

void mapTest::setUp()
{
  Set<Waypoints*> *point = std::unordered_set<Waypoints*>();
  std::unordered_map<std::wstring, Set<std::wstring>*> connections;

  //Buildings
  Waypoints tempVar(L"1", L"VCU East Engineering", 37.5451, -77.4485);
  point->add(&tempVar);
  Waypoints tempVar2(L"2", L"Gladding Residence Center", 37.5452, -77.4508);
  point->add(&tempVar2);
  Waypoints tempVar3(L"3", L"VCU W Main St Parking Deck", 37.5452, -77.4522);
  point->add(&tempVar3);
  Waypoints tempVar4(L"4", L"Altria Theater", 37.5462, -77.4518);
  point->add(&tempVar4);
  Waypoints tempVar5(L"5", L"Edward T Temple Building", 37.5454, -77.4538);
  point->add(&tempVar5);
  Waypoints tempVar6(L"6", L"Cary St Gym", 37.5443, -77.4539);
  point->add(&tempVar6);
  Waypoints tempVar7(L"7", L"VCU Department of Biology", 37.5448, -77.4549);
  point->add(&tempVar7);
  Waypoints tempVar8(L"8", L"Oliver Hall", 37.5454, -77.4551);
  point->add(&tempVar8);
  Waypoints tempVar9(L"9", L"Grace E. Harris Hall - VCU", 37.5465, -77.4549);
  point->add(&tempVar9);
  Waypoints tempVar10(L"10", L"University Student Commons", 37.5466, -77.4533);
  point->add(&tempVar10);
  Waypoints tempVar11(L"11", L"Cathedral of the Sacred Heart", 37.5476, -77.4523);
  point->add(&tempVar11);
  Waypoints tempVar12(L"12", L"Academic Learning Commons - VCU", 37.5475, -77.4544);
  point->add(&tempVar12);
  Waypoints tempVar13(L"13", L"James Branch Cabell Library", 37.5478, -77.4536);
  point->add(&tempVar13);
  Waypoints tempVar14(L"14", L"Shafer Street Cantine", 37.5481, -77.4522);
  point->add(&tempVar14);
  Waypoints tempVar15(L"15", L"Hibbs Hall", 37.5486, -77.4532);
  point->add(&tempVar15);
  Waypoints tempVar16(L"16", L"Singleton Center for the Performing Arts", 37.5488, -77.4542);
  point->add(&tempVar16);
  Waypoints tempVar17(L"17", L"VCU School of the Arts", 37.5419, -77.4547);
  point->add(&tempVar17);
  Waypoints tempVar18(L"18", L"Johnson Hall", 37.5479, -77.4510);
  point->add(&tempVar18);
  Waypoints tempVar19(L"19", L"Brandt Hall", 37.5480, -77.4501);
  point->add(&tempVar19);
  Waypoints tempVar20(L"20", L"Rhodes Hall", 37.5482, -77.4499);
  point->add(&tempVar20);
  Waypoints tempVar21(L"21", L"Franklin Street Gym", 37.5484, -77.4515);
  point->add(&tempVar21);
  Waypoints tempVar22(L"22", L"VCU Honors College", 37.5486, -77.4496);
  point->add(&tempVar22);
  Waypoints tempVar23(L"23", L"Laurel Street Deck", 37.5490, -77.4504);
  point->add(&tempVar23);
  Waypoints tempVar24(L"24", L"W Grace Street Student Housing - North", 37.5499, -77.4508);
  point->add(&tempVar24);
  Waypoints tempVar25(L"25", L"W Grace Street Student Housing - South", 37.5494, -77.4512);
  point->add(&tempVar25);
  Waypoints tempVar26(L"26", L"Monroe Park", 37.5465, -77.4505);
  point->add(&tempVar26); //MONROE PARK - Will also be considered intersection
  Waypoints tempVar27(L"27", L"Compass", 37.5481, -77.4532);
  point->add(&tempVar27); //Will also be considered intersection 
  
  
  //Intersections
 //49      point.add(new Waypoints("a", "W Main St/S Belvidere St", 37.5457, -77.4489));
 Waypoints tempVar28(L"b", L"W Main St/N Laurel St", 37.5458, -77.4515); 
 point->add(&tempVar28);
 50      point.add(new Waypoints("b", "W Main St/N Laurel St", 37.5458, -77.4515));
 51      point.add(new Waypoints("c", "W Main St/S Harrison St", 37.5458, -77.4553)); 
 52      point.add(new Waypoints("d", "S Harrison St/W Cary St", 37.5445, -77.4558));
 53      point.add(new Waypoints("e", "W Main St/Cherry St", 37.5458, -77.4528)); 
 54      point.add(new Waypoints("f", "W Main St/S Pine St", 37.5458, -77.4503)); 
 55      point.add(new Waypoints("g", "W Cary St/S Pine St", 37.5444, -77.4503)); 
 56      point.add(new Waypoints("h", "W Cary St/S Belvidere St", 37.5444, -77.4490));
 57      point.add(new Waypoints("i", "W Main St/N Linden St", 37.5458, -77.4540)); 
 58      point.add(new Waypoints("j", "Floyde Ave/N Harrison St", 37.5471, -77.4553)); 
 59      point.add(new Waypoints("k", "Floyde Ave/N Linden St", 37.5471, -77.4540)); 
 60      point.add(new Waypoints("l", "N Laurel St/S Cathedral Pl", 37.5471, -77.4515));
 61      point.add(new Waypoints("m", "N Laurel St/Cathedral Pl", 37.4574, -77.4513)); 
 62      point.add(new Waypoints("n", "Cathedral Pl/N Cathedral Pl", 37.5479, -77.4527)); 
 63      point.add(new Waypoints("o", "Floyde Ave/N Cathedral Pl", 37.5471, -77.4528));
 64      point.add(new Waypoints("p", "N Linden St/Grove Ave", 37.5484,-77.4540));
 65      point.add(new Waypoints("q", "N Harrison St/Grove Ave", 37.5485, -77.4552)); 
 66      point.add(new Waypoints("r", "N Harrison St/Park Ave", 37.5488, -77.4551)); 
 67      point.add(new Waypoints("s", "N Harrison St/W Franklin St", 37.5501, -77.5639));
 68      point.add(new Waypoints("t", "N Harrison St/W Grace St", 37.5510, -77.4531));
 69      point.add(new Waypoints("u", "Shafer St/W Franklin St", 37.5491, -77.4523));
 70      point.add(new Waypoints("v", "Shafer St/W Grace St", 37.5499, -77.4514));
 71      point.add(new Waypoints("w", "W Grace St/N Belvidere St", 37.5479, -77.4480));
 72      point.add(new Waypoints("x", "N Belvidere St/W Franklin St", 37.5470, -77.4487)); 
 73      point.add(new Waypoints("y", "W Cary St/N Laurel St", 37.5445, -77.4516));
 74      point.add(new Waypoints("z", "W Cary St/Cherry St", 37.5445, -77.4528));
 75      point.add(new Waypoints("ab", "W Cary St/S Linden St", 37.5445, -77.4540));
 76      point.add(new Waypoints("ac", "N Laurel St/W Franklin St", 37.5481, -77.4506));
 77      point.add(new Waypoints("ad", "N Laurel St/W Grace St", 37.5490, -77.498));
 78      point.add(new Waypoints("ae", "W Grace St/N Pine St", 37.5485, -77.4489));
 79      point.add(new Waypoints("af", "W Franklin St/N Pine St", 37.5476, -77.4497));



  //Edges buildings to intersections 
  connections.emplace(L"1", Stream::of(L"a", L"h").collect(Collectors::toSet()));
  connections.emplace(L"2", Stream::of(L"b", L"f", L"g", L"y").collect(Collectors::toSet()));
  connections.emplace(L"3", Stream::of(L"b", L"e", L"y", L"z").collect(Collectors::toSet()));
  connections.emplace(L"4", Stream::of(L"b", L"e").collect(Collectors::toSet()));
  connections.emplace(L"5", Stream::of(L"e", L"i", L"z", L"ab").collect(Collectors::toSet()));
  connections.emplace(L"6", Stream::of(L"z", L"ab").collect(Collectors::toSet()));
  connections.emplace(L"7", Stream::of(L"d", L"ab").collect(Collectors::toSet()));
  connections.emplace(L"8", Stream::of(L"c", L"d").collect(Collectors::toSet()));
  connections.emplace(L"9", Stream::of(L"c", L"i", L"j", L"k").collect(Collectors::toSet()));
  connections.emplace(L"10", Stream::of(L"e", L"i", L"k", L"o").collect(Collectors::toSet()));
  connections.emplace(L"11", Stream::of(L"l", L"m",L"n", L"o", L"26").collect(Collectors::toSet())); //26 = monroe park
  connections.emplace(L"12", Stream::of(L"j", L"k").collect(Collectors::toSet()));
  connections.emplace(L"13", Stream::of(L"k", L"o", L"p", L"27").collect(Collectors::toSet())); //27 = compass
  connections.emplace(L"14", Stream::of(L"27", L"n").collect(Collectors::toSet()));
  connections.emplace(L"15", Stream::of(L"27", L"p").collect(Collectors::toSet()));
  connections.emplace(L"16", Stream::of(L"p", L"q", L"r").collect(Collectors::toSet()));
  connections.emplace(L"17", Stream::of(L"r").collect(Collectors::toSet()));
  connections.emplace(L"18", Stream::of(L"l", L"m", L"ac", L"26").collect(Collectors::toSet()));
  connections.emplace(L"19", Stream::of(L"ac", L"26").collect(Collectors::toSet()));
  connections.emplace(L"20", Stream::of(L"ac", L"26").collect(Collectors::toSet()));
  connections.emplace(L"21", Stream::of(L"u", L"ac").collect(Collectors::toSet()));
  connections.emplace(L"22", Stream::of(L"ad", L"ae").collect(Collectors::toSet()));
  connections.emplace(L"23", Stream::of(L"ad").collect(Collectors::toSet()));
  connections.emplace(L"24", Stream::of(L"v").collect(Collectors::toSet()));
  connections.emplace(L"25", Stream::of(L"v").collect(Collectors::toSet()));
  connections.emplace(L"26", Stream::of(L"a", L"b", L"f", L"l", L"m", L"x", L"ac", L"af", L"11", L"18", L"19", L"20").collect(Collectors::toSet()));
  connections.emplace(L"27", Stream::of(L"n", L"p", L"u", L"13", L"14", L"15").collect(Collectors::toSet())); 
  

  //Edges intersections to intersections
  connections.emplace(L"a", Stream::of(L"f", L"l", L"m", L"ac", L"af", L"x", L"h", L"1").collect(Collectors::toSet()));
  connections.emplace(L"b", Stream::of(L"e", L"f", L"l", L"ac", L"af", L"x", L"y", L"2", L"3", L"4").collect(Collectors::toSet()));
  connections.emplace(L"c", Stream::of(L"i", L"d", L"j", L"8", L"9").collect(Collectors::toSet()));
  
  connections.put("d", Stream.of("c", "ab", "7", "8").collect(Collectors.toSet()));
 83      connections.put("e", Stream.of("b", "i", "o", "z", "3", "4", "5", "10").collect(Collectors.toSet()));
 84      connections.put("f", Stream.of("a", "b", "l", "m", "ac", "af", "x", "g", "2").collect(Collectors.toSet()));
 85      connections.put("g", Stream.of("f", "h", "ab", "2").collect(Collectors.toSet()));
 86      connections.put("h", Stream.of("a", "g", "1").collect(Collectors.toSet()));
 87      connections.put("i", Stream.of("e", "c", "ab", "k", "5", "9", "10").collect(Collectors.toSet()));
 88      connections.put("j", Stream.of("c", "k", "q", "9", "12").collect(Collectors.toSet()));
 89      connections.put("k", Stream.of("i", "j", "o", "p", "10", "12", "13").collect(Collectors.toSet()));
 90      connections.put("l", Stream.of("m", "b", "f", "a", "x", "af", "o", "9", "11", "18").collect(Collectors.toSet()));
 91      connections.put("m", Stream.of("l", "f", "a", "x", "af", "ac", "n", "11", "18").collect(Collectors.toSet()));
 92      connections.put("n", Stream.of("m", "o", "27", "11", "14").collect(Collectors.toSet()));
 93      connections.put("o", Stream.of("e", "k", "l", "n", "10", "11", "13").collect(Collectors.toSet()));
 94      connections.put("p", Stream.of("q", "r", "k", "27", "13", "15", "16").collect(Collectors.toSet()));
 95      connections.put("q", Stream.of("j", "r", "p", "16").collect(Collectors.toSet()));
 96      connections.put("r", Stream.of("p", "q", "s", "16", "17").collect(Collectors.toSet()));
 97      connections.put("s", Stream.of("r", "t", "u").collect(Collectors.toSet()));
 98      connections.put("t", Stream.of("s", "v").collect(Collectors.toSet()));
 99      connections.put("u", Stream.of("s", "v", "ac", "27", "21").collect(Collectors.toSet()));
100      connections.put("v", Stream.of("u", "t", "ad", "24", "25").collect(Collectors.toSet()));
101      connections.put("w", Stream.of("ae", "x").collect(Collectors.toSet()));
102      connections.put("x", Stream.of("a", "f", "b", "l", "m", "af").collect(Collectors.toSet()));
103      connections.put("y", Stream.of("b", "g", "z", "2", "3").collect(Collectors.toSet()));
104      connections.put("z", Stream.of("y", "ab", "e", "3", "5", "6").collect(Collectors.toSet()));
105      connections.put("ab", Stream.of("z", "d", "i", "5", "6", "7").collect(Collectors.toSet()));
106      connections.put("ac", Stream.of("m", "af", "a", "f", "b", "18", "19", "20", "21").collect(Collectors.toSet()));
107      connections.put("ad", Stream.of("v", "ac", "ae", "22", "23").collect(Collectors.toSet()));
108      connections.put("ae", Stream.of("ad", "w", "af", "22").collect(Collectors.toSet()));
109      connections.put("af", Stream.of("ae", "x", "a", "f", "b", "l", "m", "ac").collect(Collectors.toSet()));  


  map = new Graph<Waypoints>(point, connections);
  HaversineScorer tempVar28();
  HaversineScorer tempVar29();
  routeFinder = new RouteFinder<Waypoints>(map, &tempVar28, &tempVar29);

//JAVA TO C++ CONVERTER TODO TASK: A 'delete point' statement was not added since point was passed to a method or constructor. Handle memory management manually.
}

void mapTest::findRoute(const std::wstring &start, const std::wstring &end)
{
   std::vector<Waypoints*> route = routeFinder->findRoute(map->getNode(start), map->getNode(end));

   std::wcout << route.stream().map(Waypoints::getName).collect(Collectors::toList()) << std::endl;
}

void mapTest::main(std::vector<std::wstring> &args)
{
   mapTest *test = new mapTest();
   test->setUp();

   test->findRoute(L"1", L"24");

	   delete test;
}
