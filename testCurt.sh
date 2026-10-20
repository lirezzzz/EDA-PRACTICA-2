#!/bin/bash

# Executar el programa amb la in curta
./programa < t1.txt > primerSortida.txt

# Comparació silenciosa
diff -q primerSortida.txt t1_out.txt > /dev/null

if [ $? -eq 0 ]; then
    echo "OK: La sortida coincideix amb t1_out.txt"
else
    echo "ERROR: La sortida NO coincideix amb t1_out.txt"
    echo ""
    echo "Diferències:"
    diff -y --suppress-common-lines primerSortida.txt t1_out.txt
fi
