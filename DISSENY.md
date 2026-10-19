# Diseño y reparto del Ejercicio 2 (opciones d, f, g)

Documento de trabajo para los dos autores. **No va en la entrega** (dejarlo fuera del zip).

## 1. Estructura de datos (V3)

```
Establiments
 ├─ vector<Comarca> a_comarques            posición = código de comarca (1..43)
 │    Comarca
 │     ├─ vector<Establiment> a_establiments   los datos, UNA sola copia, en orden de fichero
 │     ├─ vector<Municipi> a_municipis         ordenado por código; búsqueda dicotómica
 │     │    Municipi
 │     │     ├─ vector<size_t> a_indexs         posiciones en a_establiments (orden de fichero)
 │     │     └─ map<string, Comptadors> a_carrers   calle -> contadores        (d) y (f)
 │     ├─ set<ClauTop> a_top                   10 mejores por plazas (índices)  (g)
 │     └─ a_codiMaxim / a_nMaxim               municipio máximo                 (e)
 └─ map<string,int> a_indexMunicipis       código de municipio -> comarca       (c)
```

## 2. Quién toca qué

Regla: **cada uno solo escribe dentro de sus zonas** (marcadas en el código con
`===== ZONA PERSONA A/B =====`). Así, git casi nunca ve cambios en las mismas líneas.

| Archivo | Persona A: (d) y (f) | Persona B: (g) y menú |
|---|---|---|
| `Comptadors.h/.cpp` | **todo** | — |
| `Municipi.h/.cpp` | zona A (`afegirCarrer`, `comptadorsDeCarrer`, `carrers`) | — |
| `ClauTop.h/.cpp` | — | **todo** (`operator<`) |
| `Comarca.h/.cpp` | — | zona B (`top10`, `actualitzarTop`) |
| `Establiments.h/.cpp` | zona A (`comptadorsDeCarrer`, `carrerMesEstablimentsPerComarca`) | zona B (`top10Establiments`) |
| `main.cpp` | zona A (`opcioComptadorsDeCarrer`, `opcioCarrerMesEstabliments`) | zona B (`opcioTop10Establiments`) **y** menú y renumeración |
| `CarrerResult`, `CarrerMesEstResult`, `Top10EstablimentResult` | ya hechos (solo datos), no tocar | |

**Dos únicas líneas de enlace** ya puestas en `Comarca::afegirEstabliment` (no hay que tocarlas):
- `a_municipis[pos].afegirCarrer(e.carrer(), e.places(), e.estances());` -> trabaja A.
- `actualitzarTop(index, e);` -> trabaja B.

## 3. Qué hay que rellenar (todo está como `// TODO (persona X)`)

**Persona A**
1. `Comptadors::afegir`.
2. `Municipi::afegirCarrer` y `Municipi::comptadorsDeCarrer` (usar `find`, no `[]`, en el `const`).
3. `Establiments::comptadorsDeCarrer`: `a_indexMunicipis.find` -> comarca -> `cercaDicotomica` -> municipio.
4. `opcioComptadorsDeCarrer` (el nombre de la calle lleva espacios: `getline`).
5. Después (f): `Establiments::carrerMesEstablimentsPerComarca` recorriendo `carrers()` y `opcioCarrerMesEstabliments`.

**Persona B**
1. `ClauTop::operator<`: plazas desc, estancias desc, índice asc (**orden total**).
2. `Comarca::actualitzarTop` (insertar y borrar la última si pasa de 10) y `Comarca::top10`.
3. `Establiments::top10Establiments` (control de rango como `municipisPerComarca`).
4. `opcioTop10Establiments`.
5. Menú: renumerar a 0..11 (la actual 04 pasa a ser la **05**; 04 = (d), 06 = (f), 07 = (g)) y conectar las opciones.
6. Jocs de proves (`t1..tn.txt` y sus salidas), script de bash y `llegeix.me`.

## 4. Flujo de trabajo con git

```
git pull origin main
git checkout -b feature-d        # B: feature-g
... trabajar, git add <vuestros archivos>, git commit ...
git push -u origin feature-d
```
Al terminar (con las pruebas anteriores idénticas):
```
git checkout main && git pull origin main
git merge feature-d && git push origin main
```
Avisaos antes de tocar un archivo que no sea de vuestra zona.

## 5. Comprobación antes de cada merge

Las salidas de `t1`, `t2` y `t3` del ejercicio 1 y las de los dos ficheros del profesor deben
seguir siendo **idénticas** (las opciones nuevas no cambian lo existente; la única excepción
será la renumeración del menú, que la hace B).

## 6. Decisiones abiertas (cerrarlas con el profesor o con los ficheros del Moodle)

- Qué es un "carrer": solo el nombre de la vía, o también el tipo (Calle/Avenida...). Mayúsculas y
  espacios sobrantes (hoy `Balmes` y `BALMES` serían dos calles).
- Desempate en (g) cuando coinciden plazas y estancias (propuesta actual: orden de fichero).
- Desempate en (f) cuando dos calles empatan como máximas en una comarca.
- Qué devuelven (d) y (g) cuando el municipio, la calle o la comarca no existen (propuesta: ceros / vacío).
- Formato exacto de salida (títulos y líneas) de las opciones 04, 06 y 07.
