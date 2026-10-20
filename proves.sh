#!/bin/bash
# Compila el projecte i passa tots els jocs de proves.
# Ús:  ./proves.sh          (des de qualsevol carpeta)
# Els fitxers d'entrada tenen la ruta del professor (/u/prof/dfiguls/Public/...);
# aquí es substitueix per la carpeta joc_proves/ local.
# Cal tenir joc_proves/establimentsLlarg.csv per als tests que el fan servir (no és al git).

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$DIR" || exit 1
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

echo "== Compilant =="
g++ -O2 -o "$TMP/prog" *.cpp || { echo "ERROR de compilacio"; exit 1; }

OK=0; KO=0

# prova NOM ENTRADA [SORTIDA_ESPERADA]
prova() {
    local nom="$1" entrada="$2" esperada="$3"
    if grep -q "establimentsLlarg" "$entrada" && [ ! -f joc_proves/establimentsLlarg.csv ]; then
        echo "SALTAT  $nom (falta joc_proves/establimentsLlarg.csv)"; return
    fi
    # el programa llegeix el path amb cin >> (talla als espais): fem servir enllacos a $TMP, que no en té
    sed "s#/u/prof/dfiguls/Public/#$TMP/#" "$entrada" > "$TMP/in.txt"
    local t0=$(date +%s%N)
    "$TMP/prog" < "$TMP/in.txt" > "$TMP/out.txt" 2> /dev/null
    local t=$(( ($(date +%s%N) - t0) / 1000000 ))
    if [ -z "$esperada" ]; then
        echo "EXECUTAT $nom (${t} ms) -> sortida a $DIR/sortides/$nom.txt (sense fitxer esperat)"
        mkdir -p sortides; cp "$TMP/out.txt" "sortides/$nom.txt"
    elif diff -q "$TMP/out.txt" "$esperada" > /dev/null; then
        echo "OK      $nom (${t} ms)"; OK=$((OK+1))
    else
        echo "DIFERENT $nom (${t} ms)  -> veure sortides/$nom.diff"
        mkdir -p sortides; diff "$TMP/out.txt" "$esperada" > "sortides/$nom.diff"
        KO=$((KO+1))
    fi
}

for csv in joc_proves/*.csv; do [ -f "$csv" ] && ln -sf "$DIR/$csv" "$TMP/$(basename "$csv")"; done

echo "== Proves =="
prova t1 t1.txt t1_out.txt
prova t2 t2.txt t2_out.txt
prova t3 t3.txt
prova professor_curt  joc_proves/establimentsCurtInE1.txt  joc_proves/establimentsCurtOutE1.txt
prova professor_llarg joc_proves/establimentsLlargInE1.txt joc_proves/establimentsLlargOutE1.txt

echo "== Resultat: $OK ok, $KO diferents =="
[ "$KO" -eq 0 ]
