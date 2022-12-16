cmake_minimum_required(VERSION 3.23)
project(IOI_Training)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Nachbarn GreedyAlgorithms/nachbarn.cpp)
add_executable(YingYang GreedyAlgorithms/yin_yang.cpp)
add_executable(Zwerge GreedyAlgorithms/zwerge.cpp)
add_executable(Test Test.cpp)
add_executable(HalloIOI GreedyAlgorithms/halloIOI.cpp)
add_executable(Laterne GreedyAlgorithms/laterne.cpp)
add_executable(Bufet GreedyAlgorithms/bufet.cpp)
add_executable(Geweih GreedyAlgorithms/geweih.cpp)

add_executable(FinanziellerNotstand GraphBasics/finanziellerNotstand.cpp)
add_executable(CatWalk GraphBasics/catwalk.cpp)
add_executable(Verschluesselung GraphBasics/verschluesselung.cpp)
add_executable(Konditorei GraphBasics/konditorei.cpp)
add_executable(SchachTurnier GraphBasics/schachturnier.cpp)

add_executable(Besuch KuerzesteWege/besuch.cpp)
add_executable(Musik KuerzesteWege/musik.cpp)
add_executable(Tour KuerzesteWege/tour.cpp)
add_executable(Wandern KuerzesteWege/wandern.cpp)

add_executable(Bezahlen DynamischeProgrammierung/bezahlen.cpp)
add_executable(BellmanFord DynamischeProgrammierung/bellmanford.cpp)

add_executable(Kuenstler Wettbewerbe/1.Contest/kuenstler.cpp)
add_executable(Orks Wettbewerbe/1.Contest/orks.cpp)
add_executable(Tennis Wettbewerbe/1.Contest/tennis.cpp)

add_executable(Leuchte Wettbewerbe/2.Contest/leuchte.cpp)
add_executable(Bintree Wettbewerbe/2.Contest/bintree.cpp)