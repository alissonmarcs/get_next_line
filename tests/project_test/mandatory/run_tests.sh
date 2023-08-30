#!/bin/sh

cc test_1.c ../../../libgnl.a -lbsd && ./a.out
cc test_2.c ../../../libgnl.a -lbsd && ./a.out
cc test_3.c ../../../libgnl.a -lbsd && ./a.out
cc test_4.c ../../../libgnl.a -lbsd && ./a.out
cc test_5.c ../../../libgnl.a -lbsd && ./a.out
