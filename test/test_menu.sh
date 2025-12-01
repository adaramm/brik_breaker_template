#!/bin/bash

echo "[TEST] Verificando que el programa muestra un menú..."

OUTPUT=$(timeout 1 ./juego)

if echo "$OUTPUT" | grep -qi "menu"; then
    echo "[PASS] Se detectó texto del menú."
else
    echo "[ERROR] No se detectó ningún texto que parezca menú."
    exit 1
fi
