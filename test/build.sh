#!/bin/bash

set -xe


gcc sound.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o sound


gcc click.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o click
