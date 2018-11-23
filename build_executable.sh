#!/bin/bash
set -o errexit

if [ "$1" == "--clean" ]; then
    set -o xtrace
    rm --force obj/*
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
fi
