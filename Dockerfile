FROM gcc:13.4.0

RUN apt update && apt install -y libsdl2-dev libsdl2-ttf-dev

ENV XDG_RUNTIME_DIR=/tmp/runtime-dir
RUN mkdir -p /tmp/runtime-dir

WORKDIR /app/

COPY . .

RUN make

CMD ["./snake"]

