#!/bin/bash
set -o errexit

if [ "$1" == "--clean" ]; then
    set -o xtrace
    rm --force obj/*
    rm --force test/obj/*
    rm --force bin/*
else

    # Build objects
    for SOURCE in src/*.cpp; do
        OBJECT=obj/"$(echo $(basename $SOURCE) | cut -d. -f1)".o
        CMD="g++ -Wall -std=c++98 -I./src -c -o $OBJECT $SOURCE"
        echo $CMD
        $CMD
    done

    # Build main executable
    CMD="g++ -o bin/apple_pie_experiment obj/*.o"
    echo $CMD
    $CMD

    # Build test objects
    for SOURCE in test/src/*.cpp; do
        OBJECT=test/obj/"$(echo $(basename $SOURCE) | cut -d. -f1)".o
        CMD="g++ -Wall -std=c++11 -I./src \
             -I./test/src/Catch2/single_include/catch2 -c -o $OBJECT $SOURCE"
        echo $CMD
        $CMD
    done

    # Build test executable
    CMD="g++ -o bin/apple_pie_test test/obj/*.o obj/apple_pie.o"
    echo $CMD
    $CMD

    # To test, I ran:
    #     ./bin/apple_pie_test -o report.txt > /dev/null; cat report.txt
    #
    # To open gdb on failure:
    #     gdb --args ./bin/apple_pie_test -b
    #
    # Mocking can be done with FakeIt:
    #     https://github.com/eranpeer/FakeIt

fi
