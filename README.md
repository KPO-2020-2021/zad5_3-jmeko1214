
## Faza 3, dodanie sprawdzania kolizji

W tej fazie drona udalo mi sie zrealizowac sprawdzanie czy kolizja drona z przeszkoda w miejscu potencjalnego ladawania. Sprawdzenie polega na policzeniu promienia drona oraz policzenia promienia stworzonej przeszkody. Oba promienie sa zwiekszone o 5 w celu zachowania bezpiecznego dystansu. Minusem mojej metody sprawdzania Czy_kolizja() jest to, ze gdy przeszkoda (lub po zmienieniu wymiarow drona) ma jeden bok podstawy o wiele dluzszy od drugiego (wydluzony prostokat) to wtedy promien wyraznie wystaje poza przeszkode przez co funkcja (mimo ze widac ze jest wystarczajaca duzo miejsca) wykrywa kolizje i leci dronem dalej o dlugosc podwojnego promienia drona. Druga sprawa to w chwili wykrycia kolizji, rysuje sie nowa trasa lotu ale rozpoczyna rysowanie od aktualnego polozenia drona (zaczyna rysowac od plaszczyzny a nie od miejsca startu drona). Po dokonaniu ruchu drona dodalem wyswietlanie informacji o polozeniu aktywnego drona (miejsce ladawania ostatnio uzywanego drona). Niestety nie udalo mi sie zamknac rysowanych figur, tzn. drony i plaskowyz posiadaja tylko sciany boczne, a gora_z_grania nie posiada dwoch bocznych scian.


## Building

Build by making a build directory (i.e. `build/`), run `cmake` in that dir, and then use `make` to build the desired target.

Requirements: cmake, gnuplot, doxygen + dot (in graphviz library)

Example:

``` bash
> mkdir build && cd build
> cmake .. #### options: -DCMAKE_BUILD_TYPE=[Debug | Coverage | Release], Debug is default
> make     #### compilation
> ./main   #### main() from app
> make test      #### Compile the tests
> ./unit_tests -s   #### Start the tests, -s flag - full description of each case
> make fulltest #### alternative for above, compile & run tests with full decription
> make coverage  #### Generate a coverage report
> make doc       #### Generate html documentation
```

Things to remember:
* changes to CMakeLists.txt in the main folder with new files added, i.e.:
```cpp
# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/example.cpp
    src/Dron.cpp
    src/Prostopadloscian.cpp
    src/BrylaGeometryczna.cpp
    src/Plaszczyzna.cpp
    src/Scena.cpp
    src/Wektor3D.cpp
    src/Macierz3x3.cpp
    src/Plaskowyz.cpp
    src/Gora_z_grania.cpp
    src/Gora_ostra.cpp
    src/lacze_do_gnuplota.cpp
)
set(TESTFILES        # All .cpp files in tests/
    Vector2D.cpp
    Matrix2x2.cpp
    Rectangle.cpp # etc.
)
set(LIBRARY_NAME zadX)  # Default name for the library built from src/*.cpp (change if you wish)
```
* changes to tests/CMakeLists.txt (in tests subfolder) with new files added, i.e.:
```cpp
# List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
    main.cpp
    dummy.cpp
    wektor_test.cpp
    macierz_test.cpp
)
```
The `main.cpp` in the folder `tests` is needed. Only there we define `#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN`.

The main loop of the program is in the `app` folder.

