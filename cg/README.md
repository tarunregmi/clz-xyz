## How to run

Install dependencies:

```bash
# install
sudo apt-get install -y libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev

# verify
ls /usr/lib/x86_64-linux-gnu/libglut.so.3
```

Clone repo:

```bash
git clone url
```

Run docker container:

```bash
docker compose up -d
```

Access termainl of running docker container and compile the program:

```bash
docker compose exec env bash
g++ -o main ./main.cpp -lGL -lGLU -lglut
```
