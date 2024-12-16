FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update

# Install required packages
RUN apt-get install -y \
  build-essential \
  cmake \
  git \
  pip \
  patchelf \
  libgl1-mesa-dev \
  libglu1-mesa-dev \
  freeglut3-dev \
  xorg-dev

# RUN pip install staticx

RUN apt-get autoremove && apt-get clean

WORKDIR /usr/src/app

