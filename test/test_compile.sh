#!/bin/bash

echo "Compilando con estructura include/ y src/..."

gcc -Wall -Wextra -std=c11 \
    ../src/*.c \
    test_structure.c \
    -I../include \
    -o test_structure_run

[ $? -ne 0 ] && echo "❌ No compila test_structure" && exit 1

gcc -Wall -Wextra -std=c11 ../src/*.c test_logic_ball.c     -I../include -o test_ball
gcc -Wall -Wextra -std=c11 ../src/*.c test_logic_paddle.c  -I../include -o test_paddle
gcc -Wall -Wextra -std=c11 ../src/*.c test_logic_bricks.c  -I../include -o test_bricks
gcc -Wall -Wextra -std=c11 ../src/*.c test_logic_score.c   -I../include -o test_score

echo "Ejecutando tests..."

./test_structure_run || exit 1
./test_ball          || exit 1
./test_paddle        || exit 1
./test_bricks        || exit 1
./test_score         || exit 1

echo "✅ TODOS LOS TESTS PASARON"
exit 0
