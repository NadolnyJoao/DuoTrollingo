#!/bin/bash

set -xe


gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main.o