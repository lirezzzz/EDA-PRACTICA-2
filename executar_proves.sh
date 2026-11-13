#!/bin/bash
# Script de proves de la Practica 1.
# Compila el programa i l'executa amb cada joc de proves (els fitxers tN_*.txt), una prova darrere l'altra
# i sense preguntar res. Per a cada prova compara la sortida amb la sortida esperada (la del fitxer tN_*_out.txt).
# La sortida pel canal d'error (el menu) es descarta, perque no forma part de la sortida.
# Cal executar-lo a bas.udg.edu, perque les proves llegeixen els CSV de /u/prof/dfiguls/Public/.

g++ -std=c++11 -O2 -o programa *.cpp || { echo "ERROR: el programa no compila"; exit 1; }

total=0
correctes=0
for entrada in t[0-9]*.txt; do
    # saltem les sortides esperades i les que genera aquest mateix script
    case $entrada in
        *_out.txt|*_out_meu.txt) continue ;;
    esac
    nom=${entrada%.txt}
    total=$((total + 1))
    ./programa < $entrada > ${nom}_out_meu.txt 2> /dev/null
    if diff -q ${nom}_out_meu.txt ${nom}_out.txt > /dev/null; then
        echo "OK:    $nom"
        correctes=$((correctes + 1))
    else
        echo "ERROR: $nom   (per veure les diferencies: diff ${nom}_out_meu.txt ${nom}_out.txt)"
    fi
done
echo "$correctes de $total proves correctes"
