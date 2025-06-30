# 🐍 Snake

This project is an implementation of the Snake game, created as a way to explore building a graphical game using SDL (Simple DirectMedia Layer) and C. The goal of the game is to control a snake as it moves around the screen, eating food and growing longer, while avoiding collisions with walls or itself.

## 🧩​ Structure

The project is divided into two main parts:

- **game.c**: Contains the core game logic, including snake movement, collision detection, and food management.
- **renderer.c**: Handles all rendering via SDL, displaying the game in a visually appealing way, including score updates and screen refreshes.

## ⚙️ Compilation

### Using Make

To build the project, simply run:

```
make
```

Then launch the game with:

```
./snake
```

### 🐳 Running with Docker

A Docker configuration is also available for running the game in a containerized environment.

#### Build the Docker image:

```
docker build -t snake .
```

#### Run the game:

```
xhost +local:docker

docker run -it \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  --device /dev/dri \
  snake
```

Alternatively, you can use the provided script to run everything:

```
./snake.sh
```
