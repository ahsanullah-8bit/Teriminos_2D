## Building
Note: You should have at least `cmake v3.15` and a Generator (i.e Ninja) to build and run this. *SFML* will be added as a dependency just by doing the configuration using steps below.
Run this, from the Terminos_2D directory:
	> cmake -S . -B "build" -G [Generator i.e "Ninja"]
 	> cmake --build build
	> cd build
 	> ninja

### Classes
* #### Renderer
	Does all the rendering on Board.
* #### Board
	Handles all the game except the rendering.
* #### GameController
	Have the Game loop.


## Bugs
```
* Game Over collision not detection.
* Weak random generator
```

## Future Improvements
```
* Score manager
* Sounds
```
