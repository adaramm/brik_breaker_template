#!/bin/bash

echo "[TEST] Verificando archivos obligatorios..."

FILES=(
    "src/main.c"
    "src/brick.c"
    "src/brick.h"
    "docs/especificacion.pdf"
    "README.md"
)

for f in "${FILES[@]}"
do
    if [ -f "$f" ]; then
        echo "[OK] $f encontrado"
    else
        echo "[ERROR] Falta: $f"
        exit 1
    fi
done

echo "[PASS] Todos los archivos existen."
