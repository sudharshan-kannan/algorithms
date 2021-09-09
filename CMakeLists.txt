cmake_minimum_required(VERSION 3.19)
project(algorithms_and_data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms_and_data_structures main.cpp src/generic_algorithms.cpp src/tWhitelist.cpp include/driver.h lib/LinkedList.cpp lib/LinkedList.h src/tLinkedList.cpp lib/Stack.h src/tStack.cpp src/evaluate_expressions.cpp lib/Queue.h src/tQueue.cpp lib/RingBuffer.h src/tRingBuffer.cpp src/josephus.cpp src/egg_dropping.cpp include/UnionFind.h include/QuickFind.h include/QuickUnion.h include/WeightedQuickUnion.h src/tUnionFind.cpp)