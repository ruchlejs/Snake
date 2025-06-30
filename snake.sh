#!/bin/bash

xhost +local:docker

docker build -t snake .

docker run -it \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  --device /dev/dri \
  snake
