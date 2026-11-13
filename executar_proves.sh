g++ -std=c++11 -O2 -o programa *.cpp || { echo "ERROR: el programa no compila"; exit 1; }

total=0
correctes=0
for entrada in t[0-9]*.txt; do
    # saltem les sortides esperades i les que genera aquest mateix script
    case $entrada in
        *_out.txt|*_meu.txt) continue ;;
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
